#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

long long int** create_cache(int n) {

  long long int **cache = (long long int**) malloc(n * sizeof(long long int*));

  for (int i = 0; i < n; i++) {
    cache[i] = (long long int*) malloc(n * sizeof(long long int));
  }

  return cache;
}

void release_cache(long long int** cache, int n) {
  for (int i = 0; i < n; i++) {
    free(cache[i]);
  }
  free(cache);
}

int* create_cow_distance(int n) {
  int* cow_distance = (int*) malloc(n * sizeof(int)); 
  return cow_distance;
}

void release_cow_distance(int* cow_distance) {
  free(cow_distance);
}

long long int get_noise(int left, int right, int* cow_distance, long long int** cache) {

  // For boundaries
  if (left == right) {
    return 0;
  }

  // Otherwise
  if (right > left) {

    if (cache[left][right] == 0) {
      cache[left][right] = abs(cow_distance[right] - cow_distance[left]) + get_noise(left, right - 1, cow_distance, cache);
    }

    return cache[left][right];
  }
  else {
    
    // not typo
    if (cache[left][right] == 0) {
      cache[left][right] = abs(cow_distance[left] - cow_distance[right]) + get_noise(left, right + 1, cow_distance, cache);
    }

    return cache[left][right];
  }
}

int main() {

  int n;
  scanf("%d", &n);

  // Initiation
  int* cow_distance = create_cow_distance(n);
  long long int** cache = create_cache(n);
  
  // Input
  for (int i = 0; i < n; i++) {
    scanf("%d", &cow_distance[i]);
  }

  // Main Recursive
  long long int noise = 0;
  for (int i = 0; i < n; i++) {
    noise += (get_noise(i, 0, cow_distance, cache) + get_noise(i, n - 1, cow_distance, cache));
  }

  printf("%lld\n", noise);

  // Free
  release_cow_distance(cow_distance);
  release_cache(cache, n);
  return 0;
}
