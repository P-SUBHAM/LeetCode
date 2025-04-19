ll merge(vl &arr, ll low, ll mid, ll high) {
    vl temp;
    ll left = low;
    ll right = mid + 1;
    ll cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (ll i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt;
}

ll mergeSort(vl &arr, ll low, ll high) {
    ll cnt = 0;
    if (low >= high) return cnt;
    ll mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

ll numberOfInversions(vl &a, ll n) {
    return mergeSort(a, 0, n - 1);
}
