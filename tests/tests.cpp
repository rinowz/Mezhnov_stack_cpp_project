void test_int() {
    std::string len;

    const char* filename = "../tests/Test_int.txt";
    std::ifstream fin;

    try {
        fin.open(filename);
        if (!fin.is_open()) {
            throw std::runtime_error("tests_int: Не удалось открыть файл для чтения.");
        }
        std::cout << "tests_int: You can see result in the ResTest - all good!! " << '\n';
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "tests_int: !!!  Please check Test file  !!!" << '\n';
        return;
    }

    getline(fin, len);

    std::stringstream stream(len);

    std::ofstream fout("ResTest.txt", std::ios::trunc);

    try {
        fout.is_open();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "File ResTest not have" << '\n';
    }

    int i;
    stack<int> first;
    while (stream >> i) {
        first.push(i);
    }
    fout << " TEST INT " << '\n';
    fout << first << '\n';

    fout << "Last element in this stack:" << "\t" << first.top() << '\n';

    first.pop();

    fout << "Delete last element - pop_function:" << first.top() << '\n';

    fout << "Kol-vo elements in this stack:\t" << first.size() << '\n';

    first.clear();

    fout << "Kol-vo elements after CLEAR this stack:" << first.size() << '\n';

    fout.close();
}

void test_string() {
    std::string len;

    const char* filename = "../tests/Test_string.txt";
    std::ifstream fin;

    try {
        fin.open(filename);
        if (!fin.is_open()) {
            throw std::runtime_error("tests_string: Не удалось открыть файл для чтения.");
        }
        std::cout << "tests_string: You can see result in the ResTest - all good!! " << '\n';
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "tests_string: !!!  Please check Test file  !!!" << '\n';
        return;
    }

    getline(fin, len);

    std::stringstream stream(len);

    std::ofstream fout("ResTest.txt", std::ios::app);

    try {
        fout.is_open();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "File ResTest not have" << '\n';
    }

    std::string i;
    stack<std::string> first;
    while (stream >> i) {
        first.push(i);
    }
    fout << "_____________________________________\n";
    fout << '\n' << " TEST STRING " << '\n';
    fout << first << '\n';

    fout << "Last element in this stack:" << "\t" << first.top() << '\n';

    first.pop();

    fout << "Delete last element - pop_function:" << first.top() << '\n';

    fout << "Kol-vo elements in this stack:\t" << first.size() << '\n';

    first.clear();

    fout << "Kol-vo elements after CLEAR this stack:" << first.size() << '\n';

    fout.close();
}

void test_algorithm_quicksort() {
    std::string len;

    const char* filename = "../tests/Test_int.txt";
    std::ifstream fin;

    try {
        fin.open(filename);
        if (!fin.is_open()) {
            throw std::runtime_error("test_algorithm_quicksort: Не удалось открыть файл для чтения.");
        }
        std::cout << "test_algorithm_quicksort: You can see result in the ResTest - all good!! " << '\n';
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "test_algorithm_quicksort: !!!  Please check Test file  !!!" << '\n';
        return;
    }

    getline(fin, len);

    std::stringstream stream(len);

    std::ofstream fout("ResTest.txt", std::ios::app);

    try {
        fout.is_open();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::cout << "test_algorithm_quicksort: File ResTest not have" << '\n';
    }

    int i;
    stack<int> first;
    std::vector<int> vec;
    while (stream >> i) {
        vec.push_back(i);
    }
    std::sort(vec.begin(), vec.end());
    for (int ii : vec) {
        first.push(ii);
    }
    fout << "_____________________________________\n";
    fout << " TEST QUICKSORT ALGORITHM " << '\n';
    fout << first << '\n';

    fout << "Last element in this stack:" << "\t" << first.top() << '\n';

    first.pop();

    fout << "Delete last element - pop_function:" << first.top() << '\n';

    fout << "Kol-vo elements in this stack:\t" << first.size() << '\n';

    first.clear();

    fout << "Kol-vo elements after CLEAR this stack:" << first.size() << '\n';

    fout.close();
}

void run_tests() {
    test_int();
    test_string();
    test_algorithm_quicksort();
}
