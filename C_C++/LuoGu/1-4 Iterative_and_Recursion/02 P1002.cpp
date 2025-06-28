#include <iostream>
using namespace std;

struct Pos {
	int x, y;
	Pos()=default;
	Pos(int x, int y):x(x), y(y) {};
};

struct Map {
	long long *num;
	int height, width;
	Map() = delete;
	Map(int width, int height) {
		this -> width = width;
		this -> height = height;
		num = new long long[width * height] ();
	}
	~Map() {
		delete[] num;
	}
	long long operator()(const Pos &p) const {
		if(inMap(p))
			return num[p.y * width + p.x];
		return -1;
	}
	long long &operator[](const Pos &p) {
		return num[p.y * width + p.x];
	}
	void addBlock(const Pos &block) {
		if(inMap(block))
			(*this)[block] = -1;
	}
private:
	bool inMap(const Pos &p) const{
		return p.x >= 0 && p.x < width && p.y >= 0 && p.y < height;
	}
};

int main() {
	//创建map数组来记忆每个点的路的条数，减少了重复的分支计算
	Pos hourse, B;
	cin >> B.x >> B.y >> hourse.x >> hourse.y;
	Map map(B.x + 1, B.y + 1);
	map.addBlock(hourse);
	map.addBlock(Pos(hourse.x - 1, hourse.y + 2));
	map.addBlock(Pos(hourse.x - 1, hourse.y - 2));
	map.addBlock(Pos(hourse.x + 1, hourse.y + 2));
	map.addBlock(Pos(hourse.x + 1, hourse.y - 2));
	map.addBlock(Pos(hourse.x - 2, hourse.y + 1));
	map.addBlock(Pos(hourse.x - 2, hourse.y - 1));
	map.addBlock(Pos(hourse.x + 2, hourse.y + 1));
	map.addBlock(Pos(hourse.x + 2, hourse.y - 1));

	map[Pos(0, 0)] = 1;
	for(int i = 0; i <= B.x; i++) {
		for(int j = 0; j <= B.y; j++) {
			if(i == 0 && j == 0) continue;
			Pos p = Pos(i, j);
			if(map(p) == -1)
				continue;
			else
				map[p] = (map(Pos(i - 1, j)) < 0ll?0:map(Pos(i - 1, j))) + (map(Pos(i, j - 1)) < 0ll?0:map(Pos(i, j - 1)));
		}
	}
	cout << map(B);
	
	return 0;
}
