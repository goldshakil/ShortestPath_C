#include<stdio.h>
#include<stdbool.h>
#define max 300      /*max n=300 , max m=300 */
int counter_path=0;
int total_combinations = 0;

FILE *printing_pointer;

bool solveMaze(int matrix[][max], int n, int m, int low_gate, int low_row_position, int low_col_position, int high_gate, int high_row_position, int high_col_position,int *i,int k);

bool issafe(int matrix[][max], int i, int j, int n, int m, int low_gate, int high_gate,int *c,int solution[4][4]);

bool solveutil(int matrix[][max], int solution[][max], int n, int m, int low_gate, int low_row_position, int low_col_position, int high_gate,int *i,int k);
bool solveutil_2(int matrix[][max], int solution[][max], int n, int m, int low_gate, int low_row_position, int low_col_position, int high_gate, int *i,int k);
bool solveutil_3(int matrix[][max], int solution[][max], int n, int m, int low_gate, int low_row_position, int low_col_position, int high_gate, int *i,int k);
bool solveutil_4(int matrix[][max], int solution[][max], int n, int m, int low_gate, int low_row_position, int low_col_position, int high_gate, int *i,int k);

void path_length(int k);

void path(int solution[][max], int n, int m,int low_gate,int high_gate);

int main()
{
	
	int k = 0; /*numeber of components*/

	int i = 0; int j = 0; int c = 0;

	int row_matrix[max*max]; /*300*300=90000  maximum size possible*/
	int circuit_matrix[max][max];

	int n = 0, m = 0; /*number of rows and coloumns*/

	int limit;
	/*position saving variables*/
	int k1_row = 0, k1_col = 0;
	int k2_row = 0, k2_col = 0;
	int k3_row = 0, k3_col = 0;
	int k4_row = 0, k4_col = 0;
	int k5_row = 0, k5_col = 0;

	FILE *file_pointer;



	fopen_s(&file_pointer, "hw2_input.txt", "r");
	fopen_s(&printing_pointer, "hw2_output.txt", "w");

	/*getting the size of the matrix*/
	fscanf_s(file_pointer, "%d", &n);
	fscanf_s(file_pointer, "%d", &m);

	limit = n*m;

	/***   Loop for reading the circuit  into one major array  ***/
	while (!feof(file_pointer))
	{
		if (i == limit)
		{
			break;
		}
		else if (fgetc(file_pointer))
		{
			fscanf_s(file_pointer, "%d", &row_matrix[i]);
			i++;
		}
		else
		{
			i--;
		}
	}

	/***   Defining matrix in a 2D represntation  ***/

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			circuit_matrix[i][j] = row_matrix[c];
			c++;
		}
	}

	/*finding how many components should be attached in the circuit*/
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (k<circuit_matrix[i][j])
			{
				k = circuit_matrix[i][j];

			}
		}
	}

	/* finding positions of each component*/

	if (k == 5)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (circuit_matrix[i][j] == 5)      /*position of the 5th gate*/
				{
					k5_row = i;
					k5_col = j;
				}
				if (circuit_matrix[i][j] == 4)   /*position of the 4th element*/
				{
					k4_row = i;
					k4_col = j;
				}
				if (circuit_matrix[i][j] == 3)     /*postion of the 3rd element*/
				{
					k3_row = i;
					k3_col = j;
				}
				if (circuit_matrix[i][j] == 2)    /*position of the 2nd element*/
				{
					k2_row = i;
					k2_col = j;
				}
				if (circuit_matrix[i][j] == 1)     /*postion of the 1st element*/
				{
					k1_row = i;
					k1_col = j;
				}

			}

		}
	}
	else if (k == 4)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{

				if (circuit_matrix[i][j] == 4)   /*position of the 4th element*/
				{
					k4_row = i;
					k4_col = j;
				}
				if (circuit_matrix[i][j] == 3)     /*postion of the 3rd element*/
				{
					k3_row = i;
					k3_col = j;
				}
				if (circuit_matrix[i][j] == 2)    /*position of the 2nd element*/
				{
					k2_row = i;
					k2_col = j;
				}
				if (circuit_matrix[i][j] == 1)     /*postion of the 1st element*/
				{
					k1_row = i;
					k1_col = j;
				}

			}

		}
	}
	else if (k == 3)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{

				if (circuit_matrix[i][j] == 3)     /*postion of the 3rd element*/
				{
					k3_row = i;
					k3_col = j;
				}
				if (circuit_matrix[i][j] == 2)    /*position of the 2nd element*/
				{
					k2_row = i;
					k2_col = j;
				}
				if (circuit_matrix[i][j] == 1)     /*postion of the 1st element*/
				{
					k1_row = i;
					k1_col = j;
				}

			}

		}

	}
	else if (k == 2)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (circuit_matrix[i][j] == 2)    /*position of the 2nd element*/
				{
					k2_row = i;
					k2_col = j;
				}
				if (circuit_matrix[i][j] == 1)     /*postion of the 1st element*/
				{
					k1_row = i;
					k1_col = j;
				}

			}

		}
	}

	int low_gate = 0, high_gate = 0;
	/*choosing the correct combinations of pairs depending on k value*/
	if (k == 5)
	{
		{	/*first combination (1,2)*/
			int i = 0;
			total_combinations++;
			low_gate = 1, high_gate = 2;
			solveMaze(circuit_matrix, n, m, low_gate, k1_row, k1_col, high_gate, k2_row, k2_col,&i,k);
		}

		{/*second combination(1,3)*/
		int i = 0;
		total_combinations++;
		low_gate = 1, high_gate = 3;
		solveMaze(circuit_matrix, n, m, low_gate, k1_row, k1_col, high_gate, k3_row, k3_col, &i,k);
	}

		{/* third combination(1,4)*/
			int i = 0;
			total_combinations++;
			low_gate = 1, high_gate = 4;
			solveMaze(circuit_matrix, n, m, low_gate, k1_row, k1_col, high_gate, k4_row, k4_col, &i,k);
		}

		{/*fourth combination(1,5)*/
			int i = 0;
			total_combinations++;
			low_gate = 1, high_gate = 5;
			solveMaze(circuit_matrix, n, m, low_gate, k1_row, k1_col, high_gate, k5_row, k5_col, &i,k);
		}

		{/*fifth combination(2,3)*/
			int i = 0;
			total_combinations++;
			low_gate = 2, high_gate = 3;
			solveMaze(circuit_matrix, n, m, low_gate, k2_row, k2_col, high_gate, k3_row, k3_col, &i,k);
		}

		{/*sixth combination(2,4)*/
			int i = 0;
			total_combinations++;
			low_gate = 2, high_gate = 4;
			solveMaze(circuit_matrix, n, m, low_gate, k2_row, k2_col, high_gate, k4_row, k4_col, &i,k);
		}

		{/*seventh combination(2,5)*/
			int i = 0;
			total_combinations++;
			low_gate = 2, high_gate = 5;
			solveMaze(circuit_matrix, n, m, low_gate, k2_row, k2_col, high_gate, k5_row, k5_col, &i,k);
		}

		{/*eigth combination(3,4)*/
			int i = 0;
			total_combinations++;
			low_gate = 3, high_gate = 4;
			solveMaze(circuit_matrix, n, m, low_gate, k3_row, k3_col, high_gate, k4_row, k4_col, &i,k);
		}

		{/*ninth combination(3,5)*/
			int i = 0;
			total_combinations++;
			low_gate = 3, high_gate = 5;
			solveMaze(circuit_matrix, n, m, low_gate, k3_row, k3_col, high_gate, k5_row, k5_col, &i,k);
		}

		{/*tenth combination(4,5)*/
			int i = 0;
			total_combinations++;
			low_gate = 4, high_gate = 5;
			solveMaze(circuit_matrix, n, m, low_gate, k4_row, k4_col, high_gate, k5_row, k5_col, &i,k);
		}
	}
	else if (k == 4)
	{
		{	/*first combination (1,2)*/
			int i = 0;
			total_combinations++;
			low_gate = 1, high_gate = 2;
			solveMaze(circuit_matrix, n, m, low_gate, k1_row, k1_col, high_gate, k2_row, k2_col, &i, k);
		}

		{/*second combination(1,3)*/
		int i = 0;
		total_combinations++;
		low_gate = 1, high_gate = 3;
		solveMaze(circuit_matrix, n, m, low_gate, k1_row, k1_col, high_gate, k3_row, k3_col, &i, k);
	}

		{/* third combination(1,4)*/
			int i = 0;
			total_combinations++;
			low_gate = 1, high_gate = 4;
			solveMaze(circuit_matrix, n, m, low_gate, k1_row, k1_col, high_gate, k4_row, k4_col, &i, k);
		}

		{/*fourth combination(2,3)*/
			int i = 0;
			total_combinations++;
			low_gate = 2, high_gate = 3;
			solveMaze(circuit_matrix, n, m, low_gate, k2_row, k2_col, high_gate, k3_row, k3_col, &i, k);
		}

		{/*fifth combination(2,4)*/
			int i = 0;
			total_combinations++;
			low_gate = 2, high_gate = 4;
			solveMaze(circuit_matrix, n, m, low_gate, k2_row, k2_col, high_gate, k4_row, k4_col, &i, k);
		}
		{/*sixth combination(3,4)*/
			int i = 0;
			total_combinations++;
			low_gate = 3, high_gate = 4;
			solveMaze(circuit_matrix, n, m, low_gate, k3_row, k3_col, high_gate, k4_row, k4_col, &i, k);
		}
	}

	
	else if (k == 3)
	{
		{	/*first combination (1,2)*/
			low_gate = 1, high_gate = 2;
			int i = 0;
			total_combinations++;
			solveMaze(circuit_matrix, n, m, low_gate, k1_row, k1_col, high_gate, k2_row, k2_col, &i, k);
		}

		{/*second combination(1,3)*/
		low_gate = 1, high_gate = 3;
		int i = 0;
		total_combinations++;
		solveMaze(circuit_matrix, n, m, low_gate, k1_row, k1_col, high_gate, k3_row, k3_col, &i, k);
	}

		{/* third combination(2,3)*/
			low_gate = 2, high_gate = 3;
			int i = 0;
			total_combinations++;
			solveMaze(circuit_matrix, n, m, low_gate, k2_row, k2_col, high_gate, k3_row, k3_col, &i, k);
		}
	}
	else if (k == 2)
	{
		
		{	/*first combination (1,2)*/
			int i = 0;
			total_combinations++;
			low_gate = 1, high_gate = 2;
			solveMaze(circuit_matrix, n, m, low_gate, k1_row, k1_col, high_gate, k2_row, k2_col, &i, k);
		}
	}
	fprintf(printing_pointer,"Total Path Length >> %d\n",counter_path-total_combinations);
	fclose(file_pointer);
	fclose(printing_pointer);


	printf("Please Check The Output File\n");

	return 0;
}

bool solveMaze(int matrix[][max], int n, int m, int low_gate, int low_row_position, int low_col_position, int high_gate, int high_row_position, int high_col_position, int *i,int k)
{
	int solution[100][100];  /* solution/visited path matrix*/

	fprintf(printing_pointer, " %d, %d: \t", high_gate, low_gate);

	if (solveutil(matrix, solution, n, m, low_gate, low_row_position, low_col_position, high_gate,&i,k) == false && solveutil_2(matrix, solution, n, m, low_gate, low_row_position, low_col_position, high_gate,&i,k) == false && solveutil_3(matrix, solution, n, m, low_gate, low_row_position, low_col_position, high_gate,&i,k) == false && solveutil_4(matrix, solution, n, m, low_gate, low_row_position, low_col_position, high_gate,&i,k) == false)
	{

		fprintf(printing_pointer, "no path found\n");
		total_combinations--;
		return false;
		
	}
	fprintf(printing_pointer, "\n");

	return true;
}

bool solveutil(int matrix[][max], int solution[4][4], int n, int m, int low_gate, int low_row_position, int low_col_position, int high_gate,int *i,int k)
{
	if (matrix[low_row_position][low_col_position] == high_gate)
	{
		fprintf(printing_pointer, " (%d,%d) |", low_row_position + 1, low_col_position + 1);
		path_length(k);
		solution[low_row_position][low_col_position] = 100; /* i reached to other end*/
		return true;
	}
	
	 if (issafe(matrix, low_row_position, low_col_position, n, m, low_gate, high_gate,&i,solution) == true)
	 {
	
		 solution[low_row_position][low_col_position] = 100;
		
		if (solveutil(matrix, solution, n, m, low_gate, low_row_position - 1, low_col_position, high_gate,&i,k) == true)     /*moving up*/
		{
			fprintf(printing_pointer," (%d,%d) |", low_row_position + 1, low_col_position + 1);
			path_length(k);

			return true;
		}

		if (solveutil(matrix, solution, n, m, low_gate, low_row_position, low_col_position + 1, high_gate, &i, k) == true)      /*moving right*/
		{
			fprintf(printing_pointer, " (%d,%d) |", low_row_position + 1, low_col_position + 1);
			path_length(k);

			return true;
		}

		solution[low_row_position][low_col_position] = -1;/*back trackingg*/
		return false;	
	 }

	else
	{
		return false;
	}
}
bool solveutil_2(int matrix[][max], int solution[4][4], int n, int m, int low_gate, int low_row_position, int low_col_position, int high_gate,int *i,int k)
{
	
	if (matrix[low_row_position][low_col_position] == high_gate)
	{
		fprintf(printing_pointer, " (%d,%d) |", low_row_position + 1, low_col_position + 1);
		path_length(k);

		solution[low_row_position][low_col_position] = 100; /* i reached to other end*/

		return true;
	}

	if (issafe(matrix, low_row_position, low_col_position, n, m, low_gate, high_gate,&i,solution) == true)
	{
		solution[low_row_position][low_col_position] = 100;

		if (solveutil_2(matrix, solution, n, m, low_gate, low_row_position - 1, low_col_position, high_gate, &i, k) == true)     /*moving up*/
		{
			fprintf(printing_pointer, " (%d,%d) |", low_row_position + 1, low_col_position + 1);
			path_length(k);

			return true;
		}

		if (solveutil_2(matrix, solution, n, m, low_gate, low_row_position, low_col_position - 1, high_gate, &i, k) == true)      /*moving left*/
		{
			fprintf(printing_pointer, " (%d,%d) |", low_row_position + 1, low_col_position + 1);
			path_length(k);

			return true;
		}

		solution[low_row_position][low_col_position] = -1;/*back trackingg*/
		return false;
	}

	else
	{
		return false;
	}
}

bool solveutil_3(int matrix[][max], int solution[4][4], int n, int m, int low_gate, int low_row_position, int low_col_position, int high_gate,int *i,int k)
{
	if (matrix[low_row_position][low_col_position] == high_gate)
	{
		fprintf(printing_pointer, " (%d,%d) |", low_row_position + 1, low_col_position + 1);
		path_length(k);

		solution[low_row_position][low_col_position] = 100; /* i reached to other end*/
		return true;
	}

	if (issafe(matrix, low_row_position, low_col_position, n, m, low_gate, high_gate,&i,solution) == true)
	{
		solution[low_row_position][low_col_position] = 100;

		if (solveutil_3(matrix, solution, n, m, low_gate, low_row_position + 1, low_col_position, high_gate, &i, k) == true)     /*moving down*/
		{
			fprintf(printing_pointer, " (%d,%d) |", low_row_position + 1, low_col_position + 1);
			path_length(k);

			return true;
		}

		if (solveutil_3(matrix, solution, n, m, low_gate, low_row_position, low_col_position - 1, high_gate, &i, k) == true)      /*moving left*/
		{
			fprintf(printing_pointer, " (%d,%d) |", low_row_position + 1, low_col_position + 1);
			path_length(k);

			return true;
		}

		solution[low_row_position][low_col_position] = -1;/*back trackingg*/
		return false;
	}

	else
	{
		return false;
	}


}

bool solveutil_4(int matrix[][max], int solution[4][4], int n, int m, int low_gate, int low_row_position, int low_col_position, int high_gate,int *i,int k)
{
	if (matrix[low_row_position][low_col_position] == high_gate)
	{
		fprintf(printing_pointer, " (%d,%d) |", low_row_position + 1, low_col_position + 1);
		path_length(k);

		solution[low_row_position][low_col_position] =100; /* i reached to other end*/
		return true;
	}

	if (issafe(matrix, low_row_position, low_col_position, n, m, low_gate, high_gate, &i, solution) == true)
	{
		solution[low_row_position][low_col_position] = 100;
		
		if (solveutil_4(matrix, solution, n, m, low_gate, low_row_position + 1, low_col_position, high_gate, &i, k) == true)     /*moving down*/
		{
			

			fprintf(printing_pointer, " (%d,%d) |", low_row_position + 1, low_col_position + 1);
			path_length(k);

			return true;
		}

		if (solveutil_4(matrix, solution, n, m, low_gate, low_row_position, low_col_position + 1, high_gate, &i, k) == true)      /*moving right*/
		{
			

			fprintf(printing_pointer, " (%d,%d) |", low_row_position + 1, low_col_position + 1);
			path_length(k);

			return true;
		}

		solution[low_row_position][low_col_position] = -1;/*back trackingg*/
		return false;
	}

	else
	{
		return false;
	}


}

bool issafe(int matrix[][max], int i, int j, int n, int m, int low_gate, int high_gate, int *c,int solution[4][4])
{

	
	if ((i >= 0 && i < n) && (j >= 0 && j < m) && (matrix[i][j] == 0 || matrix[i][j] == high_gate || matrix[i][j] == low_gate)&&(*c>0)&&(solution[i][j]!=100))
	{
		*c = (*c) + 1;
		return true;
	}
	else
	{

		return false;
	}
}

void path(int solution[4][4], int n, int m,int low_gate,int high_gate)
{
	

	
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d\t", solution[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void path_length(int k)
{
	counter_path=counter_path+1;

}
