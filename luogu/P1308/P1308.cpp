#include <iostream>
#include <string>

using namespace std;

void str2lower(string& s) {
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
}

int main() {
    string word;
    string article;

    getline(cin, word);
    getline(cin, article);

    str2lower(word);
    str2lower(article);

    // head ' ': make sure word and article both starts with ' '
    // tail ' ': make sure word and article both ends with ' '
    word = ' ' + word + ' ';
    article = ' ' + article + ' ';

    size_t found = article.find(word);
    if (found == string::npos) {
        cout << -1 << endl;
        return 0; // Attention: if not 0 returned, we cannot pass the test
    }
     
    int first_pos = found;
    int sum = 0;
    while (found != string::npos) {
        sum++;
        found = article.find(word, found+1);
    }
    
    cout << sum << " " << first_pos << endl;

    return 0;
}
