/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int size = employees.size();
        if (size == 0) {
            return 0;
        }
        int totalImportance = 0;
        for (int i = 0; i < size; i++) {
            if (id == employees[i]->id) {
                totalImportance += employees[i]->importance;
                int num = employees[i]->subordinates.size();
                if (num == 0) {
                    break;
                }
                for (int j = 0; j < num; j++) {
                    int tmpId = (employees[i]->subordinates)[j];
                    totalImportance += getImportance(employees, tmpId);
                }
                break;
            }
        }
        return totalImportance;
    }
};