import java.util.List;

public class EmployeeService {
    private final List<Employee> employees;

    public EmployeeService(List<Employee> employees) {
        this.employees = employees;
    }

    public void viewAllEmployees() {
        if (employees.isEmpty()) {
            System.out.println("No employees registered.");
            return;
        }
        for (Employee e : employees) {
            if (e.isDeleted()) continue;
            System.out.println(e.shortInfo());
        }
    }

    public void viewEmployeeDetails(Employee e) {
        if (e == null) {
            System.out.println("Employee not found.");
            return;
        }
        System.out.println(e.fullInfo());
    }

    public void setSalary(Employee e, double salary) {
        e.setSalary(salary);
        System.out.println("Salary updated for " + e.getName());
    }

    public void addWorkingHours(Employee e, int hours) {
        e.addWorkingHours(hours);
        System.out.println("Added " + hours + " hours to " + e.getName() + ". Total hours: " + e.getTotalWorkingHours());
        // If last addition caused overtime, show overtime info
        if (e.getTotalWorkingHours() > 160) {
            int ot = e.getTotalWorkingHours() - 160;
            System.out.println("Overtime hours now: " + ot + ". Overtime pay (calculated): " + String.format("%.2f", e.computeOvertimePay()));
        }
    }

    public void addBonus(Employee e, double amount, String reason) {
        e.addBonus(amount);
        System.out.println("Bonus added: " + amount + " Reason: " + reason);
    }

    public void deductSalary(Employee e, double amount, String reason) {
        e.addDeduction(amount);
        System.out.println("Deducted " + amount + " from " + e.getName() + ". Reason: " + reason);
    }

    public void deleteEmployee(Employee e) {
        if (e != null) {
            e.markDeleted();
            System.out.println("Employee " + e.getName() + " marked deleted (data retained in memory).");
        }
    }

    public void submitReport(Employee e, String report) {
        e.addReport(report);
        System.out.println("Report submitted.");
    }

    public void requestLeave(Employee e, String note) {
        e.addLeaveRequest(note);
        System.out.println("Leave request added.");
    }

    public void requestAdvance(Employee e, String note) {
        e.addAdvanceRequest(note);
        System.out.println("Advance salary request added.");
    }
}
