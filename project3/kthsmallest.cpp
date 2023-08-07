#include <iostream>

/**
 * problem description: Implement the algorithm kSmall, discussed in the class (Chapter 2, Section 2.4.4) by a C+
+ function. Use the first value of the array as the pivot. The partition of the array must be
  implemented using a function as well. Test your functions in a main program
 * 
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 07/06/2023
*/
/**
 * Partition the array around the pivot and return the index of the pivot element
 *
 * @param arr The array to be partitioned
 * @param low The starting index of the partition
 * @param high The ending index of the partition
 * @return The index of the pivot element
 */
int partition(int* arr, int low, int high) {
  int pivot = arr[low];  // Choose the first element as the pivot
  int i = low + 1;
  int j = high;

  while (i <= j) {
    if (arr[i] < pivot && arr[j] > pivot) {
      std::swap(arr[i], arr[j]);
      i++;
      j--;
    } else if (arr[i] >= pivot) {
      i++;
    } else if (arr[j] <= pivot) {
      j--;
    }
  }

  std::swap(arr[low], arr[j]);  // Move the pivot element to its correct position
  return j;
}

/**
 * Find the kth smallest element in the array using the kSmall algorithm
 *
 * @param arr The array of integers
 * @param size The size of the array
 * @param k The value of k for the kth smallest element
 * @return The kth smallest element
 */
int kSmall(int* arr, int size, int k) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int pivotIndex = partition(arr, low, high);

    if (pivotIndex == k - 1) {
      return arr[pivotIndex];  // Found the kth smallest element
    } else if (pivotIndex > k - 1) {
      high = pivotIndex - 1;  // Adjust the partition range for the left side of the pivot
    } else {
      low = pivotIndex + 1;  // Adjust the partition range for the right side of the pivot
    }
  }

  // If k is out of range or array is empty
  return -1;
}

int main() {
  int size;
  int k;

  std::cout << "Enter the size of the array: ";
  std::cin >> size;

  if (size <= 0) {
    std::cout << "Invalid array size." << std::endl;
    return 0;
  }

  int* arr = new int[size];  // Dynamic array allocation

  std::cout << "Enter the elements of the array: ";
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }

  std::cout << "Enter the value of k for the kth smallest element: ";
  std::cin >> k;

  if (k <= 0 || k > size) {
    std::cout << "Invalid value of k." << std::endl;
    delete[] arr;  // Release memory before exiting
    return 0;
  }

  int kthSmallest = kSmall(arr, size, k);

  if (kthSmallest != -1) {
    std::cout << "The kth smallest element is: " << kthSmallest << std::endl;
  } else {
    std::cout << "Invalid value of k or array is empty." << std::endl;
  }

  delete[] arr;  // Release memory

  return 0;
}
