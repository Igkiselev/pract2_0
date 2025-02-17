#include "userSide.h"
#include "fileProcessing.h"

std::string switch_form(EducationalForm form) {
    std::string name_form;
    switch (form) {
    case DNEV:
        name_form = "�������";
        break;
    case VECHER:
        name_form = "��������";
        break;
    case ZAOCH:
        name_form = "�������";
        break;
    }
    return name_form;
}

std::string main_entering_mode() {
    std::string in;
    getline(std::cin, in);
    while ((in != "1") && (in != "2") && (in != "0")) {
        std::cout << "�� ���������� ����, ���������� ��� ���, �������� �����������!\n";
        getline(std::cin, in);
    }
    return in;
}

std::string entering_mode() {
    std::string in;
    getline(std::cin, in);
    while ((in != "1") && (in != "2")) {
        std::cout << "�� ���������� ����, ���������� ��� ���, �������� �����������!\n";
        getline(std::cin, in);
    }
    return in;
}

// University info:

void about_univercity(Univ_database_t& unsdata) {
    std::string in;
    University_t curr_univ;
    std::cout << "�������� ������������ ��� ����������:\n";
    std::cout << "�� � ���������� ���� - ������� 1;\n������������� � ����������� ������ � ���������� ���� - ������� 2;\n";
    in = entering_mode();

    if (in == "1") {
        float cost, score;
        int code;
        std::string name;
        std::cout << "�� ������� '�� � ���������� ����'\n������� �������� ����:\n";

        do {
            getline(std::cin, name);
            code = unsdata.SearchVUZ(name, curr_univ);
            if (code == -1)
                std::cout << "���� � ����� ��������� ��� � ����, ���������� ��� ���\n";
        } while (code == -1);
        cost = curr_univ.ComputeAverageCost();
        score = curr_univ.ComputeAverageScore();

        std::cout << curr_univ;
        std::cout << "������� ���� ��� ����������� �� ����: " << score << "\n";
        std::cout << "������� ��������� �������� �� ���� : " << cost << "\n\n";
    }
    else if (in == "2") {
        std::string name;
        Spec_t s;
        int code;
        std::cout << "�� ������� '������������� � ����������� ������ � ���������� ����'\n������� �������� ����:\n";
        do {
            getline(std::cin, name);
            code = unsdata.SearchVUZ(name, curr_univ);
            if (code == -1)
                std::cout << "���� � ����� ��������� ��� � ����, ���������� ��� ���\n";
        } while (code == -1);

        int min_score;
        std::string name_form, spec_name;
        curr_univ.SearchMinScoreSpeciality(spec_name, min_score, name_form);
        std::cout << "����������� ���� ��� ����������� � ���� " << curr_univ.GetName() << ": " << min_score << "\n";
        std::cout << "��� �������������:  " << spec_name << ", ����� ��������: " << name_form << std::endl;
    }
}

// Specialty at a university:
void print_all_about_spec(Spec_t* spec_arr, int c, std::string* names_univs) {
    std::cout << "������������� " << spec_arr[0].GetName() << " ������������ � ��������� ������� �����:\n";

    for (int i = 0; i < c; i++) {
        std::cout << "��� " << names_univs[i] << ":\n";
        std::cout << spec_arr[i];
    }
}

void print_min_score_for_spec(Spec_t* spec_arr, int c, std::string* names_univs) {
    int min = 1000;
    std::string name_form, name_univ;
    EducationalForm edForm;

    for (int i = 0; i < c; i++) {
        for (int z = 0; z < spec_arr[i].GetNum_form(); z++) {
            if (spec_arr[i].Get_ExamScore(z) < min) {
                min = spec_arr[i].Get_ExamScore(z);
                edForm = spec_arr[i].Get_Form(z);
                name_form = switch_form(edForm);
                name_univ = names_univs[i];
            }
        }
    }

    std::cout << "�� ��������� ������������� ����������� ��������� ���� �� ����� �� ����������: " << min << ". ���: ";
    std::cout << name_univ << ", ����� ��������: " << name_form << std::endl;
}

void about_spec(Univ_database_t& unsdata) {
    std::cout << "�������� ������������ ��� ����������:\n";
    std::cout << "�� � ������������� - ������� 1;\n����������� ���� �� ������������� ����� ����� - ������� 2;\n";

    std::string in;
    in = entering_mode();

    if (in == "1") {
        std::string name;
        int count_such_specs = 0;
        Spec_t* specs;
        std::string* names_univs;

        std::cout << "�� ������� '�� � �������������'\n������� �������� �������������:\n";

        do {
            getline(std::cin, name);
            count_such_specs = unsdata.SearchSpecialties(name, specs, names_univs);
            if (count_such_specs == 0) {
                std::cout << "������������� � ����� ��������� �� � ����� ���� �� ���� ������ ���!, ���������� ��� ���\n";
            }
        } while (count_such_specs == 0);

        print_all_about_spec(specs, count_such_specs, names_univs);

    }
    else if (in == "2") {
        std::string name;
        int count_such_specs = 0;
        Spec_t* specs;
        std::string* names_univs;

        printf("�� ������� '����������� ���� �� ������������� ����� �����'\n������� �������� �������������:\n");

        do {
            getline(std::cin, name);
            count_such_specs = unsdata.SearchSpecialties(name, specs, names_univs);
            if (count_such_specs == 0) {
                std::cout << "������������� � ����� ��������� �� � ����� ���� �� ���� ������ ���!, ���������� ��� ���\n";
            }
        } while (count_such_specs == 0);

        print_min_score_for_spec(specs, count_such_specs, names_univs);
    }
}

void working_with_user(Univ_database_t& unsdata) {
    int end = 1;
    std::cout << "��� �� �� ������ ������?\n";
    while (end) {
        std::string in;

        std::cout << "���� ���������� ���������� � ���������� ���� - ������� 1, ���� � ���������� ������������� - 2;\n";
        std::cout << "���� �� ������ ��� ����������� ���������� � ������ ��������� ������ - ������� 0;\n\n";
        in = main_entering_mode();

        if (in == "1") {
            about_univercity(unsdata);
        }
        else if (in == "2") {
            about_spec(unsdata);

        }
        else if (in == "0") {
            std::cout << "�������, ��� ������� ���, �� ������ ������!\n";
            end = 0;
        }
        std::cout << "\n";
    }
}