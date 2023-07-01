// შექმენით სტუდენტის კლასი თავისი კონსტრუქტორით, რომელიც მოიცავს, 1. პრივატულ ცვლადს, საძიებელი
// ნიშანი. პრივატულ მეთოდებს: 2. სტუდენტების მასივის მნიშვნელობების რანდომული გენერატორით შევსება.
// გამოიყენეთ ნულოვანი სიდი: srand (time(NULL)); 3. თითოეულ სტრიქონში დაასორტიროს ზრდადობით ნიშნები.
// 4. პრივატული ცვლადის გამოყენებით იპოვოს თითოეული სტუდენტის ნიშნებში დამთხვევა (აქ იგულისხმება
// თითოეულ სტრიქონში არსებობს თუ არა მსგავსი ნიშანი, თუ არსებობს დაბეჭდოს ინდექსი თუ არ არსებობს
// დაბეჭდოს საჭირო შეტყობინება). 5. Main_ში დაბეჭდოს თითოეული სტუდენტისთვის მაქსიმალური შეფასება. 6.
// დარჩენილი შეფასებები ააჯამოს 7. დაითვალოს მათი საშუალო არითმეტიკულის მესამე ხარისხიდან ფესვი და
// დაბეჭდოს. 8. კოდში თითოეული შედეგის დაბეჭვდისას აღწერეთ თითოეული შედეგი. მასივის შევსებისას და
// სორტირებისას დაბეჭდეთ შედეგი.

#include <iostream>
#include <string>
#include <random>

using namespace std;

class Student {
    private:
    // 1. პრივატულ ცვლადს, საძიებელი ნიშანი. პრივატულ მეთოდებს:
        static const int SIZE = 5;
        string searchSymbol;
        int marks[SIZE];

    // 2. სტუდენტების მასივის მნიშვნელობების რანდომული გენერატორით შევსება. გამოიყენეთ ნულოვანი სიდი: srand (time(NULL)); 
        void valueFactory() {
            srand(time(NULL));
            searchSymbol = randomStringFactory();
            cout << "Shemtxvevitad qulebshi daemata nishnebi:" << endl;
            for (int i = 0; i < SIZE; i++) {
                marks[i] = rand() % 101;
                cout << marks[i] << ", ";
            }
        }

        string randomStringFactory() {
            string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            string output = "     ";
            for (int i = 0; i < SIZE; i++) {
                output[i] = alphabet[rand() % 27];
            }
            cout << endl <<  "shemtxvevitad dagenerirda striqoni: " << output << endl;
            return output;
        }

    // 3. თითოეულ სტრიქონში დაასორტიროს ზრდადობით ნიშნები.
        // void sortString() {
            // for (int i = 0; i < MAX_SIZE; ++i) {
                // sort(lookup[i].begin(), lookup[i].end());
            // }
        // }

        // 4. პრივატული ცვლადის გამოყენებით იპოვოს თითოეული სტუდენტის ნიშნებში დამთხვევა (აქ იგულისხმება
        // თითოეულ სტრიქონში არსებობს თუ არა მსგავსი ნიშანი, თუ არსებობს დაბეჭდოს ინდექსი თუ არ არსებობს
        // დაბეჭდოს საჭირო შეტყობინება).
        void findMatch(char match) {
            cout << endl <<"daiwyo striqon {" << searchSymbol << "} simbolo {" << match << "} zebis procesi..." << endl;
            for (int i = 0; i < SIZE; i++) {
                if (searchSymbol[i] == match){
                    cout << "simbolo " << match << " mdebareobs indeqsze: " << i << endl;
                    return;
                }
                else {
                    cout << "simbolo " << match << " ar emtxveva " << searchSymbol[i] << endl;
                }
            }
            cout << "simbolo " << match << " ar moidzebna striqonshi" << endl;
        }
    public:

        Student() {
            valueFactory();
            char symbol;
            cout << endl << "sheiyvanet nebismieri sadziebi simbolo" << endl;
            cin >> symbol;
            findMatch(symbol);
        }
        // 5. Main_ში დაბეჭდოს თითოეული სტუდენტისთვის მაქსიმალური შეფასება.
        void printMaxGrade() {
            int max = marks[0];
            for (int i = 1; i < SIZE; i++)
            {
                if (marks[i] > max)
                {
                    max = marks[i];
                }
            }
            cout << "maqsimaluri qula: " << max << endl;
        }

        // 6. დარჩენილი შეფასებები ააჯამოს
        int printSumGrade() {
            int sum = 0;
            for (int i = 0; i < SIZE; i++)
            {
                sum += marks[i];
            }
            cout << "qulebis jami: " << sum << endl;
            return sum;
        }

        // 7. დაითვალოს მათი საშუალო არითმეტიკულის მესამე ხარისხიდან ფესვი და დაბეჭდოს.
        void printMathStuff() {
            int sum = printSumGrade();
            cout << "sashuali aritmetikulis mesame xarisxidan fesvi: " << sqrt(pow((sum / SIZE), 3)) << endl;
        }
        // 8. კოდში თითოეული შედეგის დაბეჭვდისას აღწერეთ თითოეული შედეგი. მასივის შევსებისას და სორტირებისას დაბეჭდეთ შედეგი.

};

// 8. კოდში თითოეული შედეგის დაბეჭვდისას აღწერეთ თითოეული შედეგი. მასივის შევსებისას და სორტირებისას დაბეჭდეთ შედეგი.
int main() {
    const int ST_SIZE = 5;
    Student students[ST_SIZE] = {Student(), Student(), Student(), Student(), Student()};

    for (int i = 0; i < ST_SIZE; i++) {
        cout << "studenti " << i << " parametrebi: "<< endl;
        students[i].printMathStuff();
        students[i].printSumGrade();
        students[i].printMaxGrade();
        cout << endl;
    }
}

// jamshi 16 qula...