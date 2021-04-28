


typedef struct {
    int big_slot:10;
    int medium_slot:10;
    int small_slot:10;
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem *s = calloc(1, sizeof(ParkingSystem));
    s->big_slot = big;
    s->medium_slot = medium;
    s->small_slot = small;
    return s;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if (carType == 1) {
        if (!obj->big_slot)
            return false;
        obj->big_slot--;
    }
    else if (carType == 2) {
        if (!obj->medium_slot)
            return false;
        obj->medium_slot--;
    }
    else if (carType == 3) {
        if (!obj->small_slot)
            return false;
        obj->small_slot--;
    }
    return true;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/
