#include<string>
#include<iostream>
#include<bitset>
#include<map>
#include<sstream>
#include<iterator>

std::map<char, int> build_map(const std::string& str) {
	std::map <char, int> let_count;
	for (int i = 0; i < str.length(); i++) {
		let_count[str[i]]++;
	}
	return let_count;
}


bool is_unique(const std::string& str) {
	std::bitset<256> hash;
	for (int i = 0; i < str.length(); i++)
	{
		if (hash[static_cast<int>(str[i])] == true) {
			return false;
		}else {
			hash[static_cast<int>(str[i])] = true;
		}
	}
	return true;
}

std::string sorting_string(std::string sort_str) {
	for (int i = 0; i < sort_str.length(); i++) {
		for (int j = 0; j < sort_str.length(); j++) {
			if (sort_str[i] < sort_str[j]) {
				char tmp = sort_str[i];
				sort_str[i] = sort_str[j];
				sort_str[j] = tmp;
			}
			else {
				continue;
			}
		}
	}
	return sort_str;
}
bool check_permutation(std::string& str1, std::string& str2) {
	if (str1.length() != str2.length()) {
		return false;
	}
	return sorting_string(str1) == sorting_string(str2);
}


void URLify(std::string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			str.erase(i, 1);
			str.insert(i, "%20");
			i += 2;
		}
		else {
			continue;
		}
	}
}

std::string remove_space(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			str.erase(i, 1);
			i--;
		}
	}
	return str;
}
bool check_is_even(std::map <char, int> let_count, const int size) {
	int flag = 0;
	for (std::map <char, int>::iterator it = let_count.begin(); it != let_count.end(); it++) {
		if (it->second % 2 == 0) {
			continue;
		}
		else {
			flag++;
		}
	}
	if (size % 2 == 0) {
		return flag == 0 ? true : false;
	}
	else {
		return flag == 1 ? true : false;
	}
}
bool polindrome_permutation(std::string& str) {
	std::string rem_str = remove_space(str);
	std::map <char, int> let_count(build_map(str));
	return check_is_even(let_count, rem_str.length());
}

bool is_replace(std::string& str1, std::string& str2) {
	int flag = 0;
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] != str2[i]) {
			if(flag==1){
				return false;
			}
			else {
				flag++;
			}
		}
	}
	std::cout << flag << std::endl;
	return true;
}
bool is_insert(std::string& str1, std::string& str2) {
	int flag = 0;
	for (int i = 0, j = 0; i < str2.length(); j ++, i++) {
		if (str1[j] != str2[i]) {
			if (flag == 1) {
				return false;
			}
			else {
				flag++;
				j--;
			}
		}
	}
	return true;
}
bool is_remove(std::string& str1, std::string& str2) {
	int flag = 0;
	for (int i = 0, j = 0; i < str1.length(); j++, i++) {
		if (str1[i] != str2[j]) {
			if (flag == 1) {
				return false;
			}
			else {
				flag++;
				j--;
			}
		}
	}
	return true;
}
bool one_away(std::string& str1, std::string& str2) {

	switch (str2.length() - str1.length())
	{
	case 0:
		return is_replace(str1, str2);
	case 1:
		return is_insert(str1, str2);
	case -1:
		return is_remove(str1, str2);
	default:
		return false;	
	}
}

std::string compress_string(std::string& str) {
	std::ostringstream ostr;
	char tmp = str[0];
	int count = 1;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == tmp) {
			count++;
		}
		else {
			ostr << tmp;
			ostr << count;
			tmp = str[i];
			count = 1;
		}
	}
	ostr << tmp;
	ostr << count;

	return ostr.str();
}

bool rotate_string(std::string& str1, std::string& str2) {
	if (str1.length() != str2.length()) { return false; }
	if (str1.empty() && str2.empty()) { return true; }

	for (int i = 0; i < str1.length(); i++)
	{
		std::string tmp = str2.substr(i) + str2.substr(0, i) ;
		if (tmp == str1) {
			return true;
		}
	}
	return false;
}

int main() {
	std::string checked_str;
	std::string checked_str1;

	getline(std::cin, checked_str);
	getline(std::cin, checked_str1);
	//__________________________________________________________________
	// 	   Choose the function you want to check by uncommenting it 
	//__________________________________________________________________
	// 
	// 
	///******Is Unique*****/std::cout<<is_unique(checked_str) << std::endl;
	///******Permutation*****/std::cout << check_permutation(checked_str,checked_str1)<<std::endl;
	///******URLify*****/URLify(checked_str);
	///******URLify*****/std::cout << checked_str;
	///******Palindrome Permutation*****/std::cout << polindrome_permutation(checked_str) << std::endl;
	///******One Away*****/std::cout << one_away(checked_str, checked_str1) << std::endl;
	///******Compress String*****/std::cout << compress_string(checked_str) << std::endl;
	///******Rotate String*****/std::cout << rotate_string(checked_str, checked_str1) << std::endl;

	return 0;
}