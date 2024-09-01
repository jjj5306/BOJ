#include <iostream>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
 
	ios_base::sync_with_stdio(false);	// 두 표준 입출력 동기화 해제
	cin.tie(NULL);	// 입력과 출력이 묶여있는 것을 풀어준다.
	
	int T;
	cin >> T; // 테스트 케이스
 
	for (int i = 1; i <= T; i++) {
		int a;
		int b;
		cin >> a >> b;
 
		cout << "Case #" << i << ": " << a + b << "\n";
	}
	return 0;
}
