#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
    
    explicit String(const char *str) : size(strlen(str)) {
        int    i = 0;
        
        this->str = new char[this->size + 1];
        while (i < this->size) {
            this->str[i] = str[i];
            i++;
        }
        this->str[i] = '\0';
    }
    /* Реализуйте этот конструктор */
	//String(const char *str = "")

	size_t size;
	char *str;
};