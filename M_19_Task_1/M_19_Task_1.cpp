/*Задание 1. Разработка программы поиска слов в файле

Что нужно сделать
Составьте небольшой текстовый файл «words.txt», в котором последовательно,
через пробелы и переносы строк расположены различные слова. Можете использовать
любые англоязычные слова. Разработайте программу, которая искала бы среди этих
слов нужное пользователю и выводила бы общее количество повторений этого слова. 
0 — если слово вообще не присутствует в файле.*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

//Удаляет последний символ если это знак препинания
std::string word(std::ifstream& ifs) {
    
    std::string word;    

    ifs >> word;

    int a = word.find_first_of(".,!?:;");
    int b = word[word.size() - 1];

    if (word.size() - 1 == word.find_first_of(".,!?:;"))
        word.erase(word.size() - 1);

    return word;
}

void read_txt(std::vector<std::string>& text,const char* path) {

    std::ifstream ifs;
    ifs.open(path, std::ios::binary);

    if (!ifs.is_open()) {

        std::cout << "\nError open file\n";
        return;
    }
    else {

        while (!ifs.eof()) {

            text.push_back(word(ifs));
        }
        ifs.close();
    }
}

//Подсчет слов с привежением в нижний регистр
int w_search(std::vector<std::string>& text, std::string word) {

    int count = -1;

    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    for (auto p : text) {

        std::transform(p.begin(), p.end(), p.begin(), ::tolower);

        count += p == word ? 1 : 0;
    }
    return count;
}

int main()
{    

    const char* path = "D:\\Skillbox\\Module_19\\file.txt";
    std::string word;
    std::vector<std::string> text;

    read_txt(text, path);

    std::cout << "Enter a search word: ";
    std::getline(std::cin, word);

    std::cout << w_search(text, word);



}


