#include <bits/stdc++.h>
using namespace std;
const int code_meli_number = 1, students_number = 1, code_klas_number = 1, klas_number = 1,code_personaly_number= code_meli_number, code_student_number = code_meli_number;

//idnum=tedad code melli//stunum=tedad danesh amoz ha//cdnum=tedad code kelas
//klasnum=tedad class ha
int  n, i, q;
class date
{
private:
	int y, m, d;
public:
	date()
	{
		y = 1000;
		m = 0;
		d = 0;
	}
	void read_date()
	{
		while (true)
		{
			cout << endl << "\t\t\t\t\tenter year (1300)-(1400) : ";
			cin >> y;
			fflush(stdin);
			if (y >= 1300 && y <= 1400)
				break;
			cout << "\n\n\t\tERROR" << endl;
		}
		while (true)
		{
			cout << endl << "\t\t\t\t\tenter month (1)-(12) : ";
			cin >> m;
			fflush(stdin);
			if (m >= 1 && m <= 12)
				break;
			cout << "\n\n\t\tERROR" << endl;
		}
		while (true)
		{
			cout << endl << "\t\t\t\t\tenter day (1)-(30) : ";
			cin >> d;
			fflush(stdin);
			if (d >= 1 && d <= 30)
				break;
			cout << "\n\n\t\tERROR" << endl;
		}

	}
	void show_date()
	{
		cout << y << ":";
		if (m < 10)
			cout << "0" << m << ":";
		else
			cout << m << ":";
		if (d < 10)
			cout << "0" << d;
		else
			cout << d;
	}
	bool operator == (date n)
	{
		if (n.d == d)
			if (n.m == m)
				if (n.y == y)
					return true;
				else
					return false;
			else
				return false;
		else
			return false;

	}
};
class person
{
protected:
	string name, last_name, id;
	date birth_date;
public:
	void read_person()
	{
		while (true)
		{
			cout << endl << "\t\t\t\t\tenter first name : ";
			getline(cin, name);
			fflush(stdin);
			for (i = 0, q = 1; unsigned(i) < name.size();i++)
				if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' &&
					name[i] <= 'Z'))
				{
					q = 0;
					break;
				}
			if (i == name.size() && q == 1)
				break;
			cout << "\n\n\t\tERROR" << endl;
		}
		while (true)
		{
			cout << endl << "\t\t\t\t\tenter last name : ";
			getline(cin, last_name);
			fflush(stdin);
			for (i = 0, q = 1;unsigned(i) < last_name.size();i++)
				if (!(last_name[i] >= 'a' && last_name[i] <= 'z' || last_name[i] >= 'A' &&
					last_name[i] <= 'Z'))
				{
					q = 0;
					break;
				}
			if (i == last_name.size() && q == 1)
				break;
			cout << "\n\n\t\tERROR" << endl;
		}

		while (true)
		{
			cout << endl << "\t\t\t\t\tenter id : ";
			getline(cin, id);
			fflush(stdin);
			for (i = 0, q = 1;unsigned(i) < id.size();i++)
				if (!(id[i] >= '0' && id[i] <= '9' && id.size() == code_meli_number))
				{
					q = 0;
					break;
				}
			if (i == code_meli_number && q == 1)
				break;
			cout << "\n\n\t\tERROR" << endl;
		}
		cout << endl << "\t\t\t\t\tenter birthday date : ";
		birth_date.read_date();
	}
	string get_id()
	{
		return id;
	}
	void set_n(string a)
	{
		name = a;
	}
	void set_ln(string a)
	{
		last_name = a;
	}
	void set_id(string a)
	{
		id = a;
	}
	string get_n()
	{
		return name;
	}
	string get_ln()
	{
		return last_name;
	}
	date& get_bdate()
	{
		return birth_date;
	}


};
class student :public person
{
private:
	string student_id;
public:
	void read_student()
	{
		read_person();
		while (true)
		{
			cout << endl << "\t\t\t\t\tenter code student : ";
			getline(cin, student_id);
			fflush(stdin);
			for (i = 0, q = 1;unsigned(i) < student_id.size();i++)
				if (!(student_id[i] >= '0' && student_id[i] <= '9' && student_id.size() == code_student_number))
				{
					q = 0;
					break;
				}
			if (i == code_student_number && q == 1)
				break;
			cout << "\n\n\t\tERROR" << endl;
		}
	}
	void show_student()
	{
		cout << "|" << setw(20) << setfill(' ') << "|" << setw(30) << "|" << setw(15) << "|" << setw(20) << "|" << endl;
		cout << "|" << setw(19) << name << "|" << setw(29) << last_name << "|" << setw(14) << id << "|";birth_date.show_date();cout << setw(10) << "|" << endl;
		cout << "|" << setw(20) << "|" << setw(30) << "|" << setw(15) << "|" << setw(20) << "|" << endl << "|" << setw(85) << setfill('=') << "|" << endl;
	}
	void show_name_id_student()
	{
		cout << "|" << setw(20) << setfill(' ') << "|" << setw(30) << "|" << setw(15) << "|" << endl;
		cout << "|" << setw(19) << name << "|" << setw(29) << last_name << "|" << setw(14) << id << "|" << endl;
		cout << "|" << setw(20) << "|" << setw(30) << "|" << setw(15) << "|" << setw(20) << "|" << endl << "|" << setw(65) << setfill('=') << "|" << endl;
	}
};
class karmand :public person
{
protected:
	string code_pesonaly;
	date hire_date;
public:
	void read_karmand()
	{
		read_person();
		while (true)
		{
			cout << endl << "\t\t\t\t\tenter code personaly : ";
			getline(cin, code_pesonaly);
			fflush(stdin);
			for (i = 0, q = 1;unsigned(i) < code_pesonaly.size();i++)
				if (!(code_pesonaly[i] >= '0' && code_pesonaly[i] <= '9' && code_pesonaly.size() == code_personaly_number))
				{
					q = 0;
					break;
				}
			if (i == code_personaly_number && q == 1)
				break;
			cout << "\n\n\t\tERROR" << endl;
		}
		cout << endl << "\t\t\t\t\tenter hire date : ";
		hire_date.read_date();
	}
	void show_karmand()
	{
		cout << "|karmand:" << setw(12) << setfill(' ') << "|" << setw(30) << "|" << setw(15) << "|" << setw(20) << "|" << setw(20) << "|" << endl;
		cout << "|" << setw(19) << name << "|" << setw(29) << last_name << "|" << setw(14) << id << "|";birth_date.show_date();cout << setw(10) << "|";hire_date.show_date();cout << setw(10) << "|" << endl;
		cout << "|" << setw(20) << "|" << setw(30) << "|" << setw(15) << "|" << setw(20) << "|" << setw(20) << "|" << endl << "|" << setw(105) << setfill('=') << "|" << endl;
	}
};
class teacher :public karmand
{
private:
	string special_major;
public:
	void read_teacher()
	{
		read_karmand();
		while (true)
		{
			cout << endl << "\t\t\t\t\tenter special major : ";
			getline(cin, special_major);
			fflush(stdin);
			for (i = 0, q = 1; unsigned(i) < special_major.size();i++)
				if (!(special_major[i] >= 'a' && special_major[i] <= 'z' || special_major[i] >= 'A' &&
					special_major[i] <= 'Z'))
				{
					q = 0;
					break;
				}
			if (i == special_major.size() && q == 1)
				break;
			cout << "\n\n\t\tERROR" << endl;
		}
	}
	void show_teacher()
	{
		cout << "|teacher:" << setw(12) << setfill(' ') << "|" << setw(30) << "|" << setw(15) << "|" << setw(20) << "|" << endl;
		cout << "|" << setw(19) << name << "|" << setw(29) << last_name << "|" << setw(14) << id << "|";birth_date.show_date();cout << setw(10) << "|" << endl;
		cout << "|" << setw(20) << "|" << setw(30) << "|" << setw(15) << "|" << setw(20) << "|" << endl << "|" << setw(85) << setfill('=') << "|" << endl;
	}
};
class manager :public karmand
{
private:
	date expire_date,start_date;
public:
	void read_manager()
	{
		read_karmand();
		cout << endl << "\t\t\t\t\tenter start of managing date : ";
		start_date.read_date();
		cout << endl << "\t\t\t\t\tenter end of managing date : ";
		expire_date.read_date();
	}
	void show_karmand()
	{
		cout << "|manager:" << setw(12) << setfill(' ') << "|" << setw(30) << "|" << setw(15) << "|" << setw(20) << "|" << setw(20) << "|" << endl;
		cout << "|" << setw(19) << name << "|" << setw(29) << last_name << "|" << setw(14) << id << "|";birth_date.show_date();cout << setw(10) << "|";hire_date.show_date();cout << setw(10) << "|" << endl;
		cout << "|" << setw(20) << "|" << setw(30) << "|" << setw(15) << "|" << setw(20) << "|" << setw(20) << "|" << endl << "|" << setw(105) << setfill('=') << "|" << endl;
	}
};
class klas
{
private:
	student daneshjo[students_number];
	teacher  moalem;
	int code_klas;
public:
	klas()
	{
		code_klas = 0;
	}
	void read_klas()
	{
		while (true)
		{
			cout << endl << "\t\t\t\t\tenter the code of class : ";
			cin >> code_klas;
			fflush(stdin);
			if (code_klas >= 0 && code_klas <= 100)
				break;
			cout << "\n\n\t\tERROR" << endl;
		}
		cout << endl << "\t\t\t\t\tenter student details:\n\n";
		for (int i = 0;i < students_number;i++)
			daneshjo[i].read_student();
		cout << endl << "\t\t\t\t\tenter teacher details:\n\n";
		moalem.read_teacher();

	}
	void show_students_teacher()
	{
		moalem.show_teacher();
		for (int i = 0;i < students_number;i++)
			daneshjo[i].show_student();
	}
	int get_code()
	{
		return code_klas;
	}
	void set_code(int a)
	{
		code_klas = a;
	}
	teacher& get_moalem()
	{
		return moalem;
	}
	student& get_student(int h)
	{
		return daneshjo[h];
	}
};
class scholl
{
private:
	klas kls[klas_number];
	string school_name;
	karmand karman[2];
	manager modir;
	date foundation_date;
	int  code_school;
	bool l;
public:
	static int school_count;
	scholl()
	{
		code_school = -10;
		l = true;
	}
	string name_get()
	{
		return school_name;
	}
	int get_codeschool()
	{
		return code_school;
	}
	void set_name(string a)
	{
		school_name = a;
	}
	void set_code(int a)
	{
		code_school = a;
	}
	void delete_school()
	{
		l = false;
	}
	bool be()
	{
		return l;
	}
	void read_school()
	{
		school_count++;
		while (true)
		{
			cout << "\n\n\n\n\t\t\t\t\tenter school name : ";
			getline(cin, school_name);
			fflush(stdin);
			for (i = 0, q = 1;unsigned(i) < school_name.size();i++)
				if (!(school_name[i] >= 'a' && school_name[i] <= 'z' ||
					school_name[i] >= 'A' && school_name[i] <= 'Z'))
				{
					q = 0;
					break;
				}
			if (i == school_name.size() && q == 1)
				break;
			cout << "\n\n\t\tERROR" << endl;
		}
		while (true)
		{
			cout << endl << "\t\t\t\t\tenter the code of school : ";
			cin >> code_school;
			fflush(stdin);
			if (code_school >= 0 && code_school <= 100)
				break;
			cout << "\n\n\t\tERROR" << endl;
		}
		cout << endl << "\t\t\t\t\tenter the foundation date of school : ";
		foundation_date.read_date();
		cout << endl << "\t\t\t\t\tenter the information of karmand 1 : ";
		karman[0].read_karmand();
		cout << endl << "\t\t\t\t\tenter the information of karmand 2 : ";
		karman[1].read_karmand();
		cout << endl << "\t\t\t\t\tenter the information of manager : ";
		modir.read_manager();
		for (i = 0;i < code_klas_number;i++)
			kls[i].read_klas();
	}
	void show_school()
	{
		cout << endl << "|" << setw(85) << setfill('=') << "|" << endl;
		cout << "|name of school:" << setw(69) << setfill(' ') << school_name << "|" << endl;
		cout << "|code of school:" << setw(69) << setfill(' ') << code_school << "|";
		cout << endl << "|" << setw(85) << setfill('=') << "|" << endl;
		
		karman[0].show_karmand();
		karman[1].show_karmand();
		for (i = 0;i < klas_number;i++)
			kls[i].show_students_teacher();
	}
	void show_school_only()
	{
		cout << endl << "|" << setw(85) << setfill('=') << "|" << endl;
		cout << "|name of school:" << setw(69) << setfill(' ') << school_name << "|" << endl;
		cout << "|code of school:" << setw(69) << setfill(' ') << code_school << "|";
		cout << endl << "|" << setw(85) << setfill('=') << "|" << endl;
	}
	klas& get_klas(int h)
	{
		return kls[h];
	}
};
int scholl::school_count = 0;
void show_all_information(scholl s[])
{
	if (n > 1)
		for (int i = 0;i < n; i++)
			for (int j = i;j < n;j++)
				if (s[i].get_codeschool() > s[j].get_codeschool())
					swap(s[i], s[j]);
	for (int i = 0;i < n;i++)
		if (s[i].be())
			s[i].show_school();
}
void show_school_information_by_codeschool(scholl s[])
{
	int m;
	cout << endl << "enter the code of school :";
	cin >> m;
	for (int i = 0;i < n;i++)
		if (s[i].be())
			if (m == s[i].get_codeschool())
				s[i].show_school();
}
void delete_school(scholl s[])
{
	string k;
	cout << endl << "enter the name of school :";
	getline(cin, k);
	fflush(stdin);
	for (int i = 0;i < n;i++)
		if (s[i].name_get() == k)
			s[i].delete_school();

}
void show_school_information_by_idteacher(scholl s[])
{
	string k;
	cout << endl << "enter id :";
	getline(cin, k);
	fflush(stdin);
	for (int i = 0;i < n;i++)
		if (s[i].be())
			for (int j = 0;j < klas_number;j++)
				if (s[i].get_klas(j).get_moalem().get_id() == k)
					s[i].get_klas(j).get_moalem().show_teacher();
}
void show_match_name_students(scholl s[])
{
	string k, j;
	cout << endl << "enter first name :";
	getline(cin, k);
	fflush(stdin);
	cout << endl << "enter last name :";
	getline(cin, j);
	fflush(stdin);
	for (int i = 0;i < n;i++)
		if (s[i].be())
			for (int l = 0;l < klas_number;l++)
				for (int p = 0;p < students_number;p++)
					if (s[i].get_klas(l).get_student(p).get_n() == k
						&& s[i].get_klas(l).get_student(p).get_ln() == j)
					{
						s[i].show_school_only();
						s[i].get_klas(l).get_moalem().show_teacher();
						s[i].get_klas(l).get_student(p).show_student();
					}
}
void show_only_teacher(scholl s[])
{
	int m;
	cout << endl << "enter the code of school :";
	cin >> m;
	for (int i = 0;i < n;i++)
		if (s[i].be())
			if (m == s[i].get_codeschool())
				for (int l = 0;l < klas_number;l++)
					s[i].get_klas(l).get_moalem().show_teacher();
}
void show_names_id_only_student(scholl s[])
{
	for (int i = 0;i < n;i++)
		if (s[i].be())
			for (int l = 0;l < klas_number;l++)
				for (int p = 0;p < students_number;p++)
				{
					s[i].get_klas(l).get_student(p).show_name_id_student();
				}

}
void show_student_by_bdate(scholl s[])
{
	date considered_date;
	considered_date.read_date();
	for (int i = 0;i < n;i++)
		if (s[i].be())
			for (int l = 0;l < klas_number;l++)
				for (int p = 0;p < students_number;p++)
					if (s[i].get_klas(l).get_student(p).get_bdate()== considered_date)
						s[i].get_klas(l).get_student(p).show_student();
}
void edit_information(scholl s[])
{
	int m = 0, h, d;
	string k, c;
	cout << "1-Name Of School\n";
	cout << "2-ID_code Of School\n";
	cout << "3-ID_code Of Class\n";
	cout << "4-Name Of Teacher\n";
	cout << "5-Last Name Of Teacher\n";
	cout << "6-the ID_code Of Teacher\n";
	cout << "7-Birthday Of Teacher\n";
	cout << "8-Name Of Student\n";
	cout << "9-Last Name Of Student\n";
	cout << "10-ID_code Of Student\n";
	cout << "11-Birthday Of Student\n"
		<< "\n\n\nenter your mood:" << endl;
	fflush(stdin);
	fflush(stdout);
	cin >> m;
	fflush(stdin);
	fflush(stdout);
	switch (m)
	{
	case 1:
	{
		cout << "Enter The Code Of School You Want TO Edit : \t";
		cin >> h;
		cout << "\nEnter The New Name Of School : \t";
		getline(cin, k);
		fflush(stdin);
		for (int i = 0;i < n;i++)
			if (s[i].be())
				if (m == s[i].get_codeschool())
					s[i].set_name(k);
		break;
	}
	case 2:
	{
		cout << "Enter The Code Of School You Want TO Edit : \t";
		cin >> h;
		cout << "\nEnter The New ID_Code Of School : \t";
		cin >> d;
		fflush(stdin);
		for (int i = 0;i < n;i++)
			if (s[i].be())
				if (m == s[i].get_codeschool())
					s[i].set_code(d);
		break;
	}
	case 3:
	{
		cout << "Enter The Code Of Class You Want TO Edit : \t";
		cin >> h;
		cout << "\nEnter The New ID_Code Name Of Class : \t";
		cin >> d;
		fflush(stdin);
		for (int i = 0;i < n;i++)
			if (s[i].be())
				for (int l = 0;l < klas_number;l++)
					if (s[i].get_klas(l).get_code() == h)
						s[i].get_klas(l).set_code(d);
		break;
	}
	case 4:
	{
		cout << "Enter The Code Of class that Teacher teach You Want TO Edit : \t";
		cin >> h;
		cout << "Enter The New Name Of Teacher : \t";
		getline(cin, k);
		fflush(stdin);
		for (int i = 0;i < n;i++)
			if (s[i].be())
				for (int l = 0;l < klas_number;l++)
					if (s[i].get_klas(l).get_code() == h)
						s[i].get_klas(l).get_moalem().set_n(k);
		break;
	}
	case 5:
	{
		cout << "Enter The Code Of class that Teacher teach You Want TO Edit : \t";
		cin >> h;
		cout << "Enter The New last Name Of Teacher : \t";
		getline(cin, k);
		fflush(stdin);
		for (int i = 0;i < n;i++)
			if (s[i].be())
				for (int l = 0;l < klas_number;l++)
					if (s[i].get_klas(l).get_code() == h)
						s[i].get_klas(l).get_moalem().set_ln(k);
		break;
	}
	case 6:
	{
		cout << "Enter The Code Of class that Teacher teach You Want TO Edit : \t";
		cin >> h;
		cout << "Enter The New last Name Of Teacher : \t";
		getline(cin, k);
		fflush(stdin);
		for (int i = 0;i < n;i++)
			if (s[i].be())
				for (int l = 0;l < klas_number;l++)
					if (s[i].get_klas(l).get_code() == h)
						s[i].get_klas(l).get_moalem().set_id(k);
		break;
	}
	case 7:
	{
		cout << "Enter The Code Of class that Teacher teach You Want TO Edit : \t";
		cin >> h;
		fflush(stdin);
		for (int i = 0;i < n;i++)
			if (s[i].be())
				for (int l = 0;l < klas_number;l++)
					if (s[i].get_klas(l).get_code() == h)
						s[i].get_klas(l).get_moalem().get_bdate().read_date();
		break;
	}
	case 8:
	{
		cout << "Enter The id Of student You Want TO Edit : \t";
		getline(cin, k);
		fflush(stdin);
		cout << "Enter The New Name Of Student : \t";
		getline(cin, c);
		fflush(stdin);
		for (int i = 0;i < n;i++)
			if (s[i].be())
				for (int l = 0;l < klas_number;l++)
					for (int p = 0;p < students_number;p++)
						if (s[i].get_klas(l).get_student(p).get_id() == k)
							s[i].get_klas(l).get_student(p).set_n(c);
		break;
	}
	case 9:
	{
		cout << "Enter The id Of student You Want TO Edit : \t";
		getline(cin, k);
		fflush(stdin);
		cout << "Enter The New last Name Of Student : \t";
		getline(cin, c);
		fflush(stdin);
		for (int i = 0;i < n;i++)
			if (s[i].be())
				for (int l = 0;l < klas_number;l++)
					for (int p = 0;p < students_number;p++)
						if (s[i].get_klas(l).get_student(p).get_id() == k)
							s[i].get_klas(l).get_student(p).set_ln(c);
		break;
	}
	case 10:
	{
		cout << "Enter The id Of student You Want TO Edit : \t";
		getline(cin, k);
		fflush(stdin);
		cout << "Enter The New ld Of Student : \t";
		getline(cin, c);
		fflush(stdin);
		for (int i = 0;i < n;i++)
			if (s[i].be())
				for (int l = 0;l < klas_number;l++)
					for (int p = 0;p < students_number;p++)
						if (s[i].get_klas(l).get_student(p).get_id() == k)
							s[i].get_klas(l).get_student(p).set_id(c);
		break;
	}
	case 11:
	{
		cout << "Enter The id Of student You Want TO Edit : \t";
		getline(cin, k);
		fflush(stdin);
		for (int i = 0;i < n;i++)
			if (s[i].be())
				for (int l = 0;l < klas_number;l++)
					for (int p = 0;p < students_number;p++)
						if (s[i].get_klas(l).get_student(p).get_id() == k)
							s[i].get_klas(l).get_student(p).get_bdate().read_date();
		break;
	}
	}
}
int main()
{
	int m = 0;
	scholl* s;
	cout << endl << "enter the number of school :";
	cin >> n;
	s = new scholl[n];
	fflush(stdin);
	fflush(stdout);
	while (m != 14)
	{
		cout <<
			"\n1-create new school"
			"\n2-show the information"
			"\n3-enter code of school and show the shool information"
			"\n4-enter name of school and delete the school information"
			"\n5-enter teacher id and show information"
			"\n6-enter name and show the student"
			"\n7-enter code of school and show only the teacher information"
			"\n8-show the information of all students "
			"\n9-edit the information"
			"\n10-enter date and show student"
			"\n11-exit"
			"\n\n\nenter your mood:" << endl;
		fflush(stdin);
		fflush(stdout);
		cin >> m;
		fflush(stdin);
		fflush(stdout);
		switch (m)
		{
		case 1:
		{
			int temp=0;
			s[scholl::school_count].read_school();
			break;
		}
		case 3:
		{
			show_all_information(s);
			break;
		}
		case 6:
		{
			show_school_information_by_codeschool(s);
			break;
		}
		case 7:
		{
			delete_school(s);
			break;
		}
		case 8:
		{
			show_school_information_by_idteacher(s);
			break;
		}
		case 9:
		{
			show_match_name_students(s);
			break;
		}
		case 10:
		{
			show_only_teacher(s);
			break;
		}
		case 11:
		{
			show_names_id_only_student(s);
			break;
		}
		case 12:
		{
			edit_information(s);
			break;
		}
		case 13:
		{
			show_student_by_bdate(s);
			break;
		}
		}
	}
}