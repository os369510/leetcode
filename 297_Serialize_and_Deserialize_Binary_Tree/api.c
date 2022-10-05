/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <sys/queue.h>

struct entry {
    struct TreeNode *node;
    TAILQ_ENTRY(entry) entries;
};
TAILQ_HEAD(tailhead, entry) q;

void convert_val_to_two_char(int *val, unsigned char *hi, unsigned char *lo) {
    int buf;
    if (!val) {
        *hi = 0xff;
        *lo = 0xff;
        return;
    }
    buf = *val;
    if (buf < 0) {
        buf *= -1;
        *lo = buf & 0xff;
        *hi = buf >> 8;
        *hi |= 1 << 7;
        return;
    }
    buf = buf & 0xff;
    *lo = buf;
    *hi = *val >> 8;
    return;
}
void convert_two_char_to_val(int *val, unsigned char *hi, unsigned char *lo) {
    if (*hi == 0xff) {
        *val = 0xffff;
        return;
    }
    if (*hi & 0x80) {
        *hi = *hi & ~0x80;
        *val = *hi << 8;
        *val |= *lo;
        *val *= -1;
        return;
    }
    *val = *hi << 8;
    *val |= *lo;
    return;
}

void getCurrentLevel(struct TreeNode* root, int level, char *arr, int *idx) {
    unsigned char h, l;
    if (root == NULL) {
        if (level != 1)
            return;
        convert_val_to_two_char(NULL, &h, &l);
        arr[*idx] = h;
        arr[(*idx) + 1] = l;
        *idx = *idx + 2;
        return;
    }
    if (level == 1) {
        convert_val_to_two_char(&root->val, &h, &l);
        arr[*idx] = h;
        arr[(*idx) + 1] = l;
        *idx = *idx + 2;
    }
    else if (level > 1) {
        getCurrentLevel(root->left, level - 1, arr, idx);
        getCurrentLevel(root->right, level - 1, arr, idx);
    }
}

int get_height(struct TreeNode *node) {
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = get_height(node->left);
        int rheight = get_height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    if (!root) return root;

    int hei = get_height(root), idx = 0;
    int size = 10000 * 2 * 2; // 2 for pair null node, 2 for need two char
    char *ret;
    unsigned char h, l;

    ret = calloc(size + 2, sizeof(char));

    idx += 2;

    for (int i = 1; i <= hei; i++)
        getCurrentLevel(root, i, ret, &idx);

    ret[0] = idx >> 8;
    ret[1] = idx & 0xff;
    return ret;
}

void bfs(struct TreeNode *arr, int idx, int len) {
    if (idx == len) return;

    struct entry *elem = NULL, *last;
    struct TreeNode *node = NULL;
    bool break_later = false;

    last = TAILQ_LAST(&q, tailhead);

    // process the queue
    while (!TAILQ_EMPTY(&q)) {
        struct entry *eleml, *elemr;
        eleml = elemr = NULL;

        elem = TAILQ_FIRST(&q);
        node = elem->node;
        if (arr[idx].val != 65535) {
            node->left = &arr[idx];
            eleml = malloc(sizeof(struct entry));
            eleml->node = node->left;
            TAILQ_INSERT_TAIL(&q, eleml, entries);
        }
        idx++;
        if (arr[idx].val != 65535) {
            node->right = &arr[idx];
            elemr = malloc(sizeof(struct entry));
            elemr->node = node->right;
            TAILQ_INSERT_TAIL(&q, elemr, entries);
        }
        idx++;
        TAILQ_REMOVE(&q, elem, entries);
        if (last == elem)
            break_later = true;
        free(elem);

        if (break_later)
            break;
    }
    bfs(arr, idx, len);
    return;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    if (!data) return data;

    int size = 0, val, len = data[0];
    struct TreeNode *head;

    len = ((unsigned char)len) << 8;
    len |= data[1] & 0xff;
    len -= 2;
    size = len / 2;

    head = calloc(size, sizeof(struct TreeNode));
    for (int i = 0; i < size; i++) {
        convert_two_char_to_val(&val, &data[2 + 2 * i], &data[3 + 2 * i]);
        head[i].val = val;
    }

    TAILQ_INIT(&q);

    struct entry *elem;
    elem = malloc(sizeof(struct entry));
    elem->node = head;
    TAILQ_INSERT_TAIL(&q, elem, entries);
    bfs(head, 1, size);

    return head;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);,
