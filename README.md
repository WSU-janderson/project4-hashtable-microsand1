[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7RAFczHS)
# Project 4 - HashTable

Project description can be found [in the repo](Project4_HashTable.pdf)

Place your complexity analysis below.

---

insert: O(n) it needs to search the whole bucket to see if it is already inserted then inserts to that bucket
remove; O(1) to O(n) its possible to find the removal instantly but sometimes it takes the whole bucket
contains: O(1) to O(n) stops as soon as it finds the key but if it does not it searches the whole bucket
get: O(n) searches the correct hash bucket for the key needs to seach the whole bucket
operator[]:  O(n) searches the correct hash bucket for the key needs to seach the whole bucket if not found  places key into the bucket
