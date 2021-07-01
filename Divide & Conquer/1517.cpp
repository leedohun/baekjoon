#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int N;
int arr[500005];
int tmp[500005];

ll result = 0;

void merge(int left, int mid, int right) {

    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else {
            result += (ll)mid - i + 1;
            tmp[k++] = arr[j++];
        }

    if (i > mid)
        for (int t = j; t <= right; t++)
            tmp[k++] = arr[t];
    else
        for (int t = i; t <= mid; t++)
            tmp[k++] = arr[t];

    for (int t = left; t <= right; t++)
        arr[t] = tmp[t];

}

void mergeSort(int left, int right) {

    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    mergeSort(0, N - 1);

    cout << result;
}

/*
병합 정렬 과정에서 숫자가 바뀌는 만큼 체크하면서 병합 정렬을 진행
*/
