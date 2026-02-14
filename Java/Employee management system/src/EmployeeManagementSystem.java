import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class  EmployeeManagementSystem {

    // In-memory storage
    private static final List<Employee> employees = new ArrayList<>();
    private static final List<Admin> admins = new ArrayList<>();

    // Services
    private static final AuthService auth = new AuthService(admins, employees);
    private static final EmployeeService empService = new EmployeeService(employees);

    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        seedDemoAdmin();

        while (true) {
            System.out.println("\n===== Employee Management (Console - Minimal) =====");
            System.out.println("1. Sign Up (HR/Admin or Employee)");
            System.out.println("2. Sign In (HR/Admin)");
            System.out.println("3. Sign In (Employee)");
            System.out.println("4. Forgot Password");
            System.out.println("5. Exit");
            System.out.print("Choose: ");
            int ch = safeInt();

            switch (ch) {
                case 1 -> signupFlow();
                case 2 -> adminLoginFlow();
                case 3 -> employeeLoginFlow();
                case 4 -> forgotPasswordFlow();
                case 5 -> {
                    System.out.println("Goodbye.");
                    System.exit(0);
                }
                default -> System.out.println("Invalid choice.");
            }
        }
    }

    private static void seedDemoAdmin() {
        // Create a default admin to let you log in: email=admin@company.com pass=admin123
        Admin a = auth.registerAdmin("Default Admin", "admin@company.com", "01700000000", "admin123");
        System.out.println("[Demo] default admin created -> email: admin@company.com password: admin123");
    }

    // ---------------- Signup ----------------
    private static void signupFlow() {
        System.out.println("\nSign Up: Choose role");
        System.out.println("1. Admin/HR");
        System.out.println("2. Employee");
        System.out.print("Choose: ");
        int role = safeInt();
        sc.nextLine(); // consume newline

        System.out.print("Enter name: ");
        String name = sc.nextLine();
        System.out.print("Enter email: ");
        String email = sc.nextLine();
        System.out.print("Enter phone: ");
        String phone = sc.nextLine();
        System.out.print("Enter address: ");
        String address = sc.nextLine();
        System.out.print("Set password: ");
        String password = sc.nextLine();

        // Send OTP (simulated)
        auth.sendOtp(email);
        System.out.print("Enter received OTP: ");
        String otp = sc.nextLine();
        if (!auth.verifyOtp(email, otp)) {
            System.out.println("OTP verification failed. Signup aborted.");
            return;
        }

        if (role == 1) {
            Admin a = auth.registerAdmin(name, email, phone, password);
            System.out.println("Admin registered: " + a.info());
        } else {
            Employee e = auth.registerEmployee(name, email, phone, password, address);
            System.out.println("Employee registered. ID: " + e.getId());
        }
    }

    // ---------------- Admin login & menu ----------------
    private static void adminLoginFlow() {
        sc.nextLine(); // consume newline
        System.out.print("Admin email or phone: ");
        String id = sc.nextLine();
        System.out.print("Password: ");
        String pw = sc.nextLine();
        Admin a = auth.adminLogin(id, pw);
        if (a == null) {
            System.out.println("Invalid admin credentials.");
            return;
        }
        System.out.println("Welcome, " + a.getName());
        adminMenu(a);
    }

    private static void adminMenu(Admin admin) {
        while (true) {
            System.out.println("\n--- Admin Menu ---");
            System.out.println("1. View all employees");
            System.out.println("2. Search employee by ID");
            System.out.println("3. Search employee by Name");
            System.out.println("4. View employee details (by ID)");
            System.out.println("5. Set employee salary");
            System.out.println("6. Add working hours (track hours / overtime)");
            System.out.println("7. Add bonus to employee");
            System.out.println("8. Deduct salary from employee");
            System.out.println("9. Delete employee (soft)");
            System.out.println("10. Logout");
            System.out.print("Choose: ");
            int c = safeInt();
            sc.nextLine();

            switch (c) {
                case 1 -> empService.viewAllEmployees();
                case 2 -> {
                    System.out.print("Enter ID: ");
                    int id = safeInt(); sc.nextLine();
                    Employee e = auth.findEmployeeById(id);
                    if (e != null) System.out.println(e.shortInfo()); else System.out.println("Not found.");
                }
                case 3 -> {
                    System.out.print("Enter name: ");
                    String name = sc.nextLine();
                    Employee e = auth.findEmployeeByName(name);
                    if (e != null) System.out.println(e.shortInfo()); else System.out.println("Not found.");
                }
                case 4 -> {
                    System.out.print("Enter ID: ");
                    int id = safeInt(); sc.nextLine();
                    Employee e = auth.findEmployeeById(id);
                    empService.viewEmployeeDetails(e);
                }
                case 5 -> {
                    System.out.print("Enter employee ID: ");
                    int id = safeInt(); sc.nextLine();
                    Employee e = auth.findEmployeeById(id);
                    if (e == null) { System.out.println("Not found."); break; }
                    System.out.print("Enter salary amount: ");
                    double s = safeDouble(); sc.nextLine();
                    empService.setSalary(e, s);
                }
                case 6 -> {
                    System.out.print("Enter employee ID: ");
                    int id = safeInt(); sc.nextLine();
                    Employee e = auth.findEmployeeById(id);
                    if (e == null) { System.out.println("Not found."); break; }
                    System.out.print("Enter hours to add (int): ");
                    int h = safeInt(); sc.nextLine();
                    empService.addWorkingHours(e, h);
                }
                case 7 -> {
                    System.out.print("Enter employee ID: ");
                    int id = safeInt(); sc.nextLine();
                    Employee e = auth.findEmployeeById(id);
                    if (e == null) { System.out.println("Not found."); break; }
                    System.out.print("Enter bonus amount: ");
                    double b = safeDouble(); sc.nextLine();
                    System.out.print("Reason: ");
                    String r = sc.nextLine();
                    empService.addBonus(e, b, r);
                }
                case 8 -> {
                    System.out.print("Enter employee ID: ");
                    int id = safeInt(); sc.nextLine();
                    Employee e = auth.findEmployeeById(id);
                    if (e == null) { System.out.println("Not found."); break; }
                    System.out.print("Enter deduction amount: ");
                    double d = safeDouble(); sc.nextLine();
                    System.out.print("Reason: ");
                    String r = sc.nextLine();
                    empService.deductSalary(e, d, r);
                }
                case 9 -> {
                    System.out.print("Enter employee ID: ");
                    int id = safeInt(); sc.nextLine();
                    Employee e = auth.findEmployeeById(id);
                    if (e == null) { System.out.println("Not found."); break; }
                    empService.deleteEmployee(e);
                }
                case 10 -> { System.out.println("Admin logged out."); return; }
                default -> System.out.println("Invalid.");
            }
        }
    }

    // ---------------- Employee login & menu ----------------
    private static void employeeLoginFlow() {
        sc.nextLine();
        System.out.print("Email or phone: ");
        String id = sc.nextLine();
        System.out.print("Password: ");
        String pw = sc.nextLine();
        Employee e = auth.employeeLogin(id, pw);
        if (e == null) {
            System.out.println("Invalid credentials or account deleted.");
            return;
        }
        System.out.println("Welcome, " + e.getName());
        employeeMenu(e);
    }

    private static void employeeMenu(Employee e) {
        while (true) {
            System.out.println("\n--- Employee Menu ---");
            System.out.println("1. View my details");
            System.out.println("2. Update profile (name/phone/address)");
            System.out.println("3. Submit report");
            System.out.println("4. Request leave");
            System.out.println("5. Request advance salary");
            System.out.println("6. Change password");
            System.out.println("7. Logout");
            System.out.print("Choose: ");
            int c = safeInt();
            sc.nextLine();

            switch (c) {
                case 1 -> empService.viewEmployeeDetails(e);
                case 2 -> {
                    System.out.print("New name (enter to skip): ");
                    String nm = sc.nextLine();
                    if (!nm.isBlank()) e.setName(nm);
                    System.out.print("New phone (enter to skip): ");
                    String ph = sc.nextLine();
                    if (!ph.isBlank()) e.setPhone(ph);
                    System.out.print("New address (enter to skip): ");
                    String ad = sc.nextLine();
                    if (!ad.isBlank()) e.setAddress(ad);
                    System.out.println("Profile updated.");
                }
                case 3 -> {
                    System.out.print("Write report: ");
                    String r = sc.nextLine();
                    empService.submitReport(e, r);
                }
                case 4 -> {
                    System.out.print("Leave note/reason: ");
                    String lr = sc.nextLine();
                    empService.requestLeave(e, lr);
                }
                case 5 -> {
                    System.out.print("Advance request note (include amount desired): ");
                    String ar = sc.nextLine();
                    empService.requestAdvance(e, ar);
                }
                case 6 -> {
                    System.out.print("Enter current password: ");
                    String curr = sc.nextLine();
                    if (!e.getPassword().equals(curr)) {
                        System.out.println("Current password doesn't match.");
                        break;
                    }
                    System.out.print("Enter new password: ");
                    String nw = sc.nextLine();
                    e.setPassword(nw);
                    System.out.println("Password changed.");
                }
                case 7 -> { System.out.println("Logged out."); return; }
                default -> System.out.println("Invalid.");
            }
        }
    }

    // ---------------- Forgot password ----------------
    private static void forgotPasswordFlow() {
        sc.nextLine();
        System.out.print("Enter your registered email or phone: ");
        String id = sc.nextLine();
        boolean found = auth.forgotPasswordProcess(id);
        if (!found) {
            System.out.println("Identifier not found for any account.");
            return;
        }
        System.out.print("Enter OTP you received: ");
        String otp = sc.nextLine();
        if (!auth.verifyOtp(id, otp)) {
            System.out.println("OTP incorrect. Abort.");
            return;
        }
        System.out.print("Enter new password: ");
        String np = sc.nextLine();
        boolean ok = auth.resetEmployeePassword(id, np);
        if (ok) System.out.println("Password reset successful.");
        else System.out.println("Failed to reset (admin password reset not supported here).");
    }

    // ----------------- helpers -----------------
    private static int safeInt() {
        while (!sc.hasNextInt()) {
            sc.nextLine();
            System.out.print("Enter a valid integer: ");
        }
        int v = sc.nextInt();
        return v;
    }

    private static double safeDouble() {
        while (!sc.hasNextDouble()) {
            sc.nextLine();
            System.out.print("Enter a valid number: ");
        }
        double v = sc.nextDouble();
        return v;
    }
}
