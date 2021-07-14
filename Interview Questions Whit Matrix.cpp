#include<iostream>
#include<vector>

const int size = 6;

void swap_matrix(int arr[size][size]) {
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = i; j < size - i - 1; j++) {
			int tmp = arr[i][j];
			arr[i][j] = arr[size - 1 - j][i];
			arr[size - 1 - j][i] = arr[size - 1 - i][size - 1 - j];
			arr[size - 1 - i][size - 1 - j] = arr[j][size - 1 - i];
			arr[j][size - 1 - i] = tmp;
		}
	}
}

void set_zeros(int arr[size][size]) {
	std::vector<int> col_index;
	bool set_row = false;
	int tmp;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			if (set_row) {
				if (j > tmp && arr[i][j] == 0) {
					tmp = j;
					col_index.push_back(j);
				}
				arr[i][j] = 0;
			}
			else {
				if (arr[i][j] == 0) {
					set_row = true;
					col_index.push_back(j);
					tmp = j;
					j = -1;
				}
			}
		}
		set_row = false;

	}

	for (int j : col_index) 
		for (int i = 0; i < size; i++)
			arr[i][j] = 0;
}

int main() {
	int arr[size][size]{ { 0 } };
	std::cout << "Plese input the elements of Matrix" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << "Elements of "<< i <<"th row:" << std::endl;
		for (int j = 0; j < size; j++)
			std::cin >> arr[i][j];
	}
	//__________________________________________________________________
	// 	   Choose the function you want to check by uncommenting it 
	//__________________________________________________________________
	// 
	// 
	///******Swap Matrix*****/swap_matrix(arr);
	///******Swap Matrix*****/std::cout << "This is your matrix whit swaped colums and rows:" << std::endl;
	///******Set Zeros*****/set_zeros(arr);
	///******Set Zeros*****/std::cout << "This is your matrix whit seted zeros in colums and rows where one element is equal zero:" << std::endl;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			std::cout << arr[i][j] << "  ";
		std::cout << std::endl;
	}

	return 0;
}