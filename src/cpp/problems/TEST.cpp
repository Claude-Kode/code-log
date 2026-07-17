// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int test_count = 0;

void solve() { 
	test_count++;
	
	// 生成数据
	system("mkd.exe > in.txt");               
	
	// 运行你的程序（在上级目录）
	system("..\\std.exe < in.txt > out1.txt");    
	
	// 运行暴力程序
	system("brute.exe < in.txt > out2.txt");  
	
	// 比较结果
	if (system("fc out1.txt out2.txt > nul")) {  
		cout << "❌ WA 第" << test_count << "次" << endl;
		cout << endl << "输入数据：" << endl;
		system("type in.txt");
		cout << endl << "你的输出：" << endl;
		system("type out1.txt");
		cout << endl << "暴力输出：" << endl;
		system("type out2.txt");
		
		// 保存失败用例
		system("copy in.txt failed_input.txt 2>nul");
		system("copy out1.txt failed_my.txt 2>nul");
		system("copy out2.txt failed_brute.txt 2>nul");
		
		cout << endl << "错误数据已保存到失败文件" << endl;
		
		// 直接退出程序
		exit(0);
	} else {
		cout << "✅ AC 第" << test_count << "次" << endl;
	}
	
	// 清理临时文件
	system("del in.txt out1.txt out2.txt 2>nul");
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout << "=== 对拍程序 ===" << endl;
	
	int tt;
	cout << "请输入对拍次数: ";
	cin >> tt;
	
	cout << endl << "开始对拍，共 " << tt << " 次..." << endl;
	cout << "按 Ctrl+C 可提前终止" << endl << endl;
	
	for (int i = 0; i < tt; i++) {
		solve();
	}
	
	cout << endl << "🎉 全部 " << tt << " 次测试通过！" << endl;
	system("pause");
	return 0;
}