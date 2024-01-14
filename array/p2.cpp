#include <iostream>
using namespace std;

class Array {
private:
    int* arr;
    int n;
public:
    Array(int size){
        arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = 0;
        }
        n = 0;
    }
    ~Array(){
        delete[] arr;
    }

    int at(int idx) {
        return arr[idx];
    }
    void set(int idx, int X){
        if(arr[idx] == 0){
            cout << 0 << endl;
        }else{
            arr[idx] = X;
        }
    }
    void add(int idx, int X){
        if(n == 0){
            arr[0] = X;
        }
        else if(idx >= n){
            arr[n] = X;
        }else{
            for(int i = n - 1; i >= idx; i--){
                arr[i + 1] = arr[i];
            }
            arr[idx] = X;
        }
        n++;
    }

    int remove(int idx) {
        if(n == 0 || idx >= n) {
            return 0;
        }
        else {
            int x = arr[idx];
            for(int i = idx; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arr[n - 1] = 0;
            n--;
            return x;
        }
    }

    void printArray() const {
        if(n == 0) {
            cout << 0 << endl;
            return;
        }
        for(int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};
int main() {

    int m;
    cin >> m;
    Array arr =  10000;
    string cmd;
    int idx, x;
    for(int i = 0; i < m; i++){
        cin >> cmd;
        if(cmd == "at"){
            cin >> idx;
            cout << arr.at(idx) << endl;
        }
        else if(cmd == "set"){
            cin >> idx >> x;
            arr.set(idx, x);
        }
        else if(cmd == "add"){
            cin >> idx >> x;
            arr.add(idx, x);
        }
        else if(cmd == "remove"){
            cin >> idx;
            cout << arr.remove(idx) << endl;
        }
        else if(cmd == "printArray"){
            arr.printArray();
        }
    }

    return 0;
}