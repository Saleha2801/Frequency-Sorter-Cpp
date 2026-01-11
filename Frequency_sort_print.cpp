#include <iostream>
using namespace std;
void frequency_sort(int n, int arr[]) {
    int unique[n], freq[n], unique_count = 0;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < unique_count; j++) {
            if (arr[i] == unique[j]) {
                freq[j]++;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            unique[unique_count] = arr[i];
            freq[unique_count] = 1;
            unique_count++;
            
        }
    }
    for (int i = 0; i < unique_count - 1; i++) {
        for (int j = i + 1; j < unique_count; j++) {
            if (freq[i] < freq[j] || (freq[i] == freq[j] && unique[i] > unique[j])) {
                int temp = freq[i]; 
                freq[i] = freq[j]; 
                freq[j] = temp;
                temp = unique[i]; 
                unique[i] = unique[j]; 
                unique[j] = temp;
            }
        }
    }
    for (int i = 0; i < unique_count; i++) {
        for (int j = 0; j < freq[i]; j++) {
            cout << unique[i] << " ";
        }
    }
    cout << endl;
}
int main() {
    cout<<"Name: Saleha Shaikh";
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    frequency_sort(n, arr);
}
