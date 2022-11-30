//#include "FieldSettings.h"
//void FieldSettings::start(Field& field) {
//	system("cls");
//	char set;
//	std::cout << "- Press '1' to set map size (Size must be 10-15)\n- Press any button to continue with default map (10x10)\n";
//	std::cin >> set;
//	switch (set)
//	{
//	case '1':
//		int size = 0;
//		while (true) {
//			system("cls");
//			std::cout << "Map size: ";
//			std::cin >> size;
//			if (std::cin.fail()) {					// ���������� �� �������������
//				// ���������� ���� ��������� ������� � goodbit,
//				// ����� �� ����� ������������ ignore()
//				std::cin.clear();					// ������� ������������ ���� �� ������
//				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//				// ����������� �����
//				notify(new ErrLevel, FIELD);		//�������� ������
//				getchar();
//				continue;
//			}
//			// ������� ����� �������������� ���� �� ������
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			if (std::cin.gcount() > 1)				// ���� �� ������� ����� ������ ��������������� �������
//			{
//				notify(new ErrLevel, FIELD);
//				getchar();
//				continue;							// ����� ������� ���� ���� ������������
//			}
//
//			if (size < 10 || size > 15)				// ���������, ��� �������� ����� �����
//			{
//				notify(new ErrLevel, FIELD);
//				getchar();
//				continue;
//			}
//
//			break;
//		}
//		field = Field(size);
//		break;
//	}
//	system("cls");
//	std::cout << "'W' - Up\n'A' - Left\n'S' - Down\n'D' - Right\n'G' - Pray to the Gods\n'X' - Exit\n\nPress any button to start\n";
//	getchar();
//}
//
//void FieldSettings::attach(ILogObserver* observer)
//{
//	list_observer_.push_back(observer);
//}
//
//void FieldSettings::detach(ILogObserver* observer)
//{
//	list_observer_.remove(observer);
//}
//
//void FieldSettings::notify(LogLevel* messagelvl, int key)
//{
//	std::list<ILogObserver*>::iterator iterator = list_observer_.begin();
//	while (iterator != list_observer_.end()) {
//		//��� �������� ������ ��������� 
//		(*iterator)->update(messagelvl, key);
//		++iterator;
//	}
//	delete messagelvl;
//}
