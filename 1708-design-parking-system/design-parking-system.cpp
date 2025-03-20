class ParkingSystem {
public:
    vector<int>arr;
    ParkingSystem(int big, int medium, int small) {
        arr.resize(3,0);
        arr[0]=big;
        arr[1]=medium;
        arr[2]=small;
    }
    bool addCar(int carType) {
        if(arr[carType-1]>0){
            arr[carType-1]--;
            return 1;
        }
        return 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */