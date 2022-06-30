//二分查找
int BinarySearch(Elemtype arr[], int size, Elemtype target) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (target > arr[mid]) {
			left = mid + 1;
		}
		else if (target < arr[mid]) {
			right = mid - 1;
		}
		else return mid;
	}
	return -1;
}

//查找第一个与key相等的元素
int Binary_FirstEqual_Search(Elemtype arr[], int size, Elemtype target) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (target > arr[mid]) {
			left = mid + 1;
		}
		else if (target < arr[mid]) {
			right = mid - 1;
		}
		else {
			if (mid == left || arr[mid - 1] != target) {
				return mid;
			}
			else {
				right = mid + 1;
			}
		}
	}
	return -1;
}

//查找最后一个与key相等的元素
int Binary_LastEqual_Search(Elemtype arr[], int size, Elemtype target) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left >> 1);
		if (target > arr[mid]) {
			left = mid + 1;
		}
		else if (target < arr[mid]) {
			right = mid - 1;
		}
		else {
			if (mid == right || arr[mid + 1] != target) {
				return mid;
			}
			else {
				left = mid + 1;
			}
		}
	}
	return -1;
}

//查找第一个大于等于key值的元素
int Binary_FirstB_Search(Elemtype arr[], int size, Elemtype target) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left >> 1);
		if (target <= arr[mid]) {
			if (mid == left || target > arr[mid - 1]) return mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}

//查找最后一个小于等于key值的元素
int Binary_LastS_Search(Elemtype arr[], int size, Elemtype target) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left >> 1);
		if (target <= arr[mid]) {
			if (mid == right || arr[mid + 1] > target) {
				return mid;
			}
			else {
				left = mid + 1;
			}
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}
