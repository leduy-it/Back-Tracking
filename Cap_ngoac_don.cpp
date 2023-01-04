#include <iostream>
#include <vector>
using namespace std;

//Hàm sử dụng để khởi tạo tất cả n cặp ngoặc lồng nhau đúng quy tắc
// int open: đếm số lượng ngoặc mở trong chuỗi hiện hành s đã khởi tạo
// int close: Đếm số lượng ngoặc đóng trong chuỗi hiện hành s đã khởi tạo
// String s: Chuỗi hiện hành đã được khởi tạo.
// String / result: a vector(mảng) để lưu lại chuỗi ngoặc đơn đúng quy tắc
void generateParenthesis(int n, int open, int close,
                         string s, vector<string>& result)
{
    //    Nếu tổng biến đếm open và biến đếm close cộng lại bằng n
    // thì ta đã thu được chuỗi ngoặc đơn hợp lệ. Vì vậy ta trả về
    // và in ra kết quả.
    if (open == n && close == n) {
        result.push_back(s);
        return;
    }
    
    // Nếu biến open vẫn nhỏ hơn n thì tiếp tục thêm vào chuỗi
    // hiện hành một ngoặc mở và tiếp tục đệ quy hàm generateParenthesis với giá trị open tăng thêm 1
    // đến khi nào mà open vẫn nhỏ hơn n
    if (open < n) {
        generateParenthesis(n, open + 1, close, s + "(",
                            result);
    }
    
    // Nếu biến close vẫn nhỏ hơn n thì tiếp tục thêm vào chuỗi
    // hiện hành một ngoặc đóng và tiếp tục đệ quy hàm generateParenthesis với giá trị close tăng thêm 1
    // đến khi nào mà open vẫn nhỏ hơn n
    if (close < open) {
        generateParenthesis(n, open, close + 1, s + ")",
                            result);
    }
}

int main()
{
    int n;
    cin>>n;

    // Tạo 1 vector(hoặc mảng động) để lưu giá trị chuỗi ngoặc đơn hiện hành
    vector<string> result;
    
    //Lời gọi hàm và khởi tạo giá trị đếm open(ngoặc mở), close(ngoặc đóng) bằng 0
    //đại diện cho chuỗi hiện hành khi bắt đầu là 0 ngoặc đóng , 0 ngoặc mở.
    // và một chuỗi s khởi tạo rỗng được lưu trữ vào vector result
    generateParenthesis(n, 0, 0, "", result);
   
    // Đây là bước in chuỗi hiện hành thu được sau lời gọi hàm( và trong hàm đó đệ quy tứ tung) ở trên./
    for (auto s : result) {
        cout << s << endl;
    }
    return 0;
}
