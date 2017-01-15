#define SIZE 20
#define SP 2
struct node
{
		int v;
		char d;
};
class GAME
{
		public:
		node mp[SIZE][SIZE];
		int hx,hy;
		int tx,ty;
		int fx,fy;
		char hd;
		char inp;
		int l;
		int diff;
		// util.cpp
		void print_map();
		void init();
		// move.cpp
		void moveBody();
		void moveTail();
		void moveHead();
		void move();
		// misc.cpp
		void addNode();
		void genFood();
		
};
//void print_map();
