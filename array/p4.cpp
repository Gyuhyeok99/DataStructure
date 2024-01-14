#include <iostream>
using namespace std;
int average(int sum, int per);
int main() {
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        int size;
        cin >> size;
        int arr[size];
        int kSum = 0, jSum = 0, cSum = 0;
        int kPer = 0, jPer = 0, cPer = 0;
        for(int i = 0; i < size; i++) {
            int money;
            cin >> money;
            arr[i] = money;
            if(i % 3 == 0){
                kSum += arr[i];
                if(arr[i] != 0){
                    kPer++;
                }
            }else if(i % 3 == 1) {
                jSum += arr[i];
                if(arr[i] != 0){
                    jPer++;
                }
            }else {
                cSum += arr[i];
                if(arr[i] != 0){
                    cPer++;
                }
            }
        }
        cout << kSum << " " << jSum << " " << cSum << endl;
        int kAvg = average(kSum, kPer), jAvg =  average(jSum, jPer), cAvg = average(cSum, cPer);
        cout << kAvg << " " << jAvg << " " << cAvg << endl;

    }
}
int average(int sum, int per){
    if(per == 0 ){
        return 0;
    }
    int avg = sum / per;
    return avg;
}
