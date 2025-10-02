class Solution {
public:
    int maxBottlesDrunk(int nb, int ne) {
        int total=nb;
        while(nb>=ne){
            total++;
            nb-=ne;
            nb++;
            ne++;
        }
        return total;
    }
};