#include <stdio.h>
#include <string.h>


#define	MAX_COLUMNS				10
#define	MAX_COLUMNS_WIDTH	20

void print_table_header(const char* headers[MAX_COLUMNS], int ncols, int cols_width[MAX_COLUMNS]){
	printf("+");
	for (int i = 0; i < ncols; i++){
		for(int j = 0; j < cols_width[i] + 2; j++)	printf("-");
		printf("+");
	}
	//printf("+");
	printf("\n");

	// print columns name
	printf("|");
	for (int i = 0; i < ncols; i++){
		printf(" %-*s |", cols_width[i], headers[i]);
	}
	printf("\n");
	printf("+");
	for (int i = 0; i < ncols; i++){
		for (int j = 0; j < cols_width[i] + 2; j++){	printf("-");	}
		printf("+");
	}
	printf("\n");
}


void print_table_row(const char* data[MAX_COLUMNS], int ncols, int nrows, int cols_width[MAX_COLUMNS]){
	printf("|");
	for (int i = 0; i < ncols; i++){
		printf(" %-*s |", cols_width[i], data[i]);
	}
	printf("\n");
}


void print_table_footer(int ncols, int cols_width[MAX_COLUMNS]){
	printf("+");
	for (int i = 0; i < ncols; i++){
		for (int j = 0; j < cols_width[i] + 2; j++){
			printf("-");
		}
		printf("+");
	}
	printf("\n");
}


void print_table(const char *headers[MAX_COLUMNS], int ncols, const char* data[][MAX_COLUMNS], int nrows){
	if (ncols > MAX_COLUMNS || ncols <= 0){
		return;
	}

	int cols_width[MAX_COLUMNS] = {0};
	for (int i = 0; i < ncols; i++)	{
		cols_width[i] = strlen(headers[i]);
		for (int j = 0; j < nrows; j++)	{
			int data_len = strlen(data[j][i]);
			if (data_len > cols_width[i] && data_len <= MAX_COLUMNS_WIDTH){
				cols_width[i] = data_len;
			}
		}
		if (cols_width[i] >= MAX_COLUMNS_WIDTH)	{
			cols_width[i] = MAX_COLUMNS_WIDTH;
		}
	}
	print_table_header(headers, ncols, cols_width);
	for (int i = 0; i < nrows; i++)
		print_table_row(data[i], ncols, nrows, cols_width);
	print_table_footer(ncols, cols_width);
}
int main(void){
	const char *headers[MAX_COLUMNS] = {"id", "name", "address"};
	int ncols = 3;
	const char *data[MAX_COLUMNS][MAX_COLUMNS] = {{"123", "rk", "NULL"}, {"124", "pavi", "sindhanoor"}};
	int nrows = 2;
	print_table(headers, ncols, data, nrows);
	return 0;
}
