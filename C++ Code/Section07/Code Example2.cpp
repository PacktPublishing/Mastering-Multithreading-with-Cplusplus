class Foo {
    static std::map<int, std::string> strings;
    static std::string oneString;
public:
   static void init(int a, std::string b, std::string c) {
         strings.insert(std::pair<int, std::string>(a, b));
         oneString = c;
 }
};
std::map<int, std::string> Foo::strings;
std::string Foo::oneString;

class Bar {
   static std::string name;
   static std::string initName();
public:
   void init();
};
// Static initializations.
std::string Bar::name = Bar::initName();

std::string Bar::initName() {
   Foo::init(1, "A", "B");
   return "Bar";
}

class Foo {
   static std::map<int, std::string>& strings();
   static std::string oneString;
public:
   static void init(int a, std::string b, std::string c) {
         static std::map<int, std::string> stringsStatic = Foo::strings();
         stringsStatic.insert(std::pair<int, std::string>(a, b));
         oneString = c;
   }
};
std::string Foo::oneString;

std::map<int, std::string>& Foo::strings() {
   static std::map<int, std::string>* stringsStatic = new std::map<int,
std::string>();
   return *stringsStatic;
}
