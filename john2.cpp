// 1.  შექმენით  ცარიელი  10  წევრიანი  წრფივი  მასივი  და  შეავსეთ  მნიშნველობები  რანდომული  რიცხვებით 
// გამოიყენეთ ნულოვანი სიდი:  srand (time(NULL));. 2. შექმენით მეთოდი რომელიც მიმთითებლის გამოყენებით 
// (*) მასივის სორტიტებას მოახდენს კლებადობის მიხედვით. 3. Main_ში შექმენით მარტივი სამ პირობიანი 
// სვიჩი(switch), რომლის თითოეული პირობა იქნება 4 ზე ნაშთი (1, 2, 3 ან 0). 4. კოდში თითოეული შედეგის 
// დაბეჭვდისას  აღწერეთ  თითოეული  შედეგი.  მასივის  შევსებისას  და  სორტირებისას  დაბეჭდეთ  შედეგი.  5. 
// Main()_ში ინიციალიზაცია გაუკეთეთ ორ სტრინგს, შეადარეთ ეს ორი სტრინგი ერთმანეთს strcmp() ფუნქციის 
// მეშვეობით  და  დაბეჭდეთ  საჭირო  შედეგი  შეტყობინებით.  6.  გადაწერეთ  პირველი  სტრინგის  პირველი  5 
// სიმბოლო მეორე სტრინგის ბოლოს და დაბეჭდეთ საჭირო შედეგი შეტყობინებით. 7. დაბეჭდეთ პირველი 
// სტრინგის პირველი სიმბოლოს რიცხვითი მნიშვნელობა და 8. მეორე სტრინგი გადაიყვანეთ UperCase_შi

#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

void fillArray(int *arr, int size) {
    cout << "masivi iyo shevsebuli ricxvebit:" << endl;
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101;
        cout << arr[i] << ", ";
    }
    cout << endl;
}
// 2. შექმენით მეთოდი რომელიც მიმთითებლის გამოყენებით (*) მასივის სორტიტებას მოახდენს კლებადობის მიხედვით.
void sortArray(int *arr, int size) {
    sort(arr, arr+size, greater<int>());
    cout << "masivi iyo sortirebuli klebadobit: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main() {
    // შექმენით  ცარიელი  10  წევრიანი  წრფივი  მასივი  და  შეავსეთ  მნიშნველობები  რანდომული  რიცხვებით გამოიყენეთ ნულოვანი სიდი:  srand (time(NULL))
    srand(time(NULL));
    static const int SIZE = 10;
    int array[SIZE];
    fillArray(array, SIZE);
    
    //3. Main_ში შექმენით მარტივი სამ პირობიანი სვიჩი(switch), რომლის თითოეული პირობა იქნება 4 ზე ნაშთი (1, 2, 3 ან 0)
    cout << "sheiyvanet nebismieri mteli nishani" << endl;
    int x;
    cin >> x;

    switch (x % 4){
    case 0:
        cout << "sheyvani nishnis nashti 4 ze gayofisas aris 0";
        break;
    
    case 1:
        cout << "sheyvani nishnis nashti 4 ze gayofisas aris 1";
        break;
    case 2:
        cout << "sheyvani nishnis nashti 4 ze gayofisas aris 2";
        break;
    case 3:
        cout << "sheyvani nishnis nashti 4 ze gayofisas aris 3";
        break;
    }
    cout << endl << endl;


    // 5. Main()_ში ინიციალიზაცია გაუკეთეთ ორ სტრინგს, შეადარეთ ეს ორი სტრინგი ერთმანეთს strcmp() ფუნქციის  მეშვეობით  და  დაბეჭდეთ 
    // საჭირო  შედეგი  შეტყობინებით.
    string first = "Pirveli";
    string second = "meore";
    
    cout << "stringi {" << first << "} shedarebisas string {" << second << "}-ze strcmp() metodit shedegi aris:" << endl;
    cout << first.compare(second) << endl;
    
    // 6.  გადაწერეთ  პირველი  სტრინგის  პირველი 5 სიმბოლო მეორე სტრინგის ბოლოს და დაბეჭდეთ საჭირო შედეგი შეტყობინებით.
    second = second + first.substr(0, 5);
    cout << "pirveli stringis 5 asos sheerteba meore stringis bolos shedegi: " << second << endl;

    // 7. დაბეჭდეთ პირველი სტრინგის პირველი სიმბოლოს რიცხვითი მნიშვნელობა და
    cout << "pirveli stringis pirveli aso {" << first[0] << "} ricxviti mnishvneloba: " << endl;
    cout << first[0] + 0 << endl;
    
    // 8. მეორე სტრინგი გადაიყვანეთ UperCase_შi
    cout << "meore stringi {" << second << "} gadayvana upperCase-Shi: " << endl;
    transform(second.begin(), second.end(), second.begin(), ::toupper);
    cout << second;

}

// jamshi 20 qula...