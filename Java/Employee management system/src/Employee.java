import java.util.ArrayList;
import java.util.List;

public class Employee {
    private static int NEXT_ID = 1;

    private final int id;
    private String name;
    private String email;
    private String phone;
    private String password;
    private String address = "";
    private double salary = 0.0;
    private double bonus = 0.0;
    private double deductions = 0.0;
    private int totalWorkingHours = 0;
    private List<String> reports = new ArrayList<>();
    private List<String> leaveRequests = new ArrayList<>();
    private List<String> advanceRequests = new ArrayList<>();
    private boolean isDeleted = false;

    public Employee(String name, String email, String phone, String password, String address) {
        this.id = NEXT_ID++;
        this.name = name;
        this.email = email;
        this.phone = phone;
        this.password = password;
        this.address = address;
    }

    public int getId() { return id; }
    public String getName() { return name; }
    public String getEmail() { return email; }
    public String getPhone() { return phone; }
    public String getPassword() { return password; }
    public String getAddress() { return address; }
    public double getSalary() { return salary; }
    public double getBonus() { return bonus; }
    public double getDeductions() { return deductions; }
    public int getTotalWorkingHours() { return totalWorkingHours; }
    public boolean isDeleted() { return isDeleted; }

    public void setName(String name) { this.name = name; }
    public void setEmail(String email) { this.email = email; }
    public void setPhone(String phone) { this.phone = phone; }
    public void setPassword(String password) { this.password = password; }
    public void setAddress(String address) { this.address = address; }
    public void setSalary(double salary) { this.salary = salary; }
    public void addBonus(double b) { this.bonus += b; }
    public void addDeduction(double d) { this.deductions += d; }
    public void addWorkingHours(int h) { this.totalWorkingHours += h; }
    public void addReport(String r) { this.reports.add(r); }
    public void addLeaveRequest(String lr) { this.leaveRequests.add(lr); }
    public void addAdvanceRequest(String ar) { this.advanceRequests.add(ar); }
    public List<String> getReports() { return reports; }
    public List<String> getLeaveRequests() { return leaveRequests; }
    public List<String> getAdvanceRequests() { return advanceRequests; }
    public void markDeleted() { this.isDeleted = true; }

    public double computeOvertimePay() {
        // We'll consider 160 working hours in a month (40*4) as full time.
        if (totalWorkingHours <= 160) return 0.0;
        int overtimeHours = totalWorkingHours - 160;
        double hourlyRate = salary / 160.0;
        // overtime paid at 1.5x
        return overtimeHours * hourlyRate * 1.5;
    }

    public double currentPayable() {
        return salary + bonus + computeOvertimePay() - deductions;
    }

    public String shortInfo() {
        return String.format("ID:%d  Name:%s  Email:%s  Phone:%s  Salary:%.2f", id, name, email, phone, salary);
    }

    public String fullInfo() {
        StringBuilder sb = new StringBuilder();
        sb.append("=== Employee Details ===\n");
        sb.append("ID: ").append(id).append("\n");
        sb.append("Name: ").append(name).append("\n");
        sb.append("Email: ").append(email).append("\n");
        sb.append("Phone: ").append(phone).append("\n");
        sb.append("Address: ").append(address).append("\n");
        sb.append(String.format("Salary: %.2f\n", salary));
        sb.append(String.format("Bonus (total): %.2f\n", bonus));
        sb.append(String.format("Deductions (total): %.2f\n", deductions));
        sb.append("Total Working Hours (month): ").append(totalWorkingHours).append("\n");
        sb.append(String.format("Overtime Pay (calc): %.2f\n", computeOvertimePay()));
        sb.append(String.format("Payable Now (salary+bonus+overtime-deductions): %.2f\n", currentPayable()));
        sb.append("Reports Submitted: ").append(reports.size()).append("\n");
        sb.append("Leave Requests: ").append(leaveRequests.size()).append("\n");
        sb.append("Advance Requests: ").append(advanceRequests.size()).append("\n");
        return sb.toString();
    }
}
