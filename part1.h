#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <time.h>

#define PAGE_SIZE 256
#define FRAME_SIZE 256

#define TLB_ENTRIES 16

#define MM_SIZE 128
#define PT_SIZE 256

#define PHYS_MEM_SIZE 65536


#define tlb_rw 0.5
#define mm_rw 100
#define disk_rw 250000

#define num_of_tests 10000

#define MYADDR "myaddresses.txt"


int phys_mem[MM_SIZE];
int page_table[PT_SIZE][2];
int tlb[TLB_ENTRIES][2];

int num_of_tlb_hits = 0;
int num_of_page_faults = 0;

void init_vm();
void init_phys_mem();
void init_tlb();
bool check_arg(int argc, char* argv[]);
void print_statistics();
void run_vmm(char* addr);
int get_offset(std::string addr);
int get_page_num(std::string addr);
bool is_in_tlb(int page_num);
int calc_phys_addr(int page_num, int offset);
bool page_fault(int page_table_num);
void generate_rands();
int fRand(int fMax);
void write_on_file(int data);
int menu();
