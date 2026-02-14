import java.util.*;

public class AuthService {
    private final List<Admin> admins;
    private final List<Employee> employees;
    private final Random random = new Random();
    private final Map<String, String> pendingOtp = new HashMap<>(); // identifier -> otp

    public AuthService(List<Admin> admins, List<Employee> employees) {
        this.admins = admins;
        this.employees = employees;
    }

    // Simulate sending OTP to email/phone by generating and returning OTP.
    public String sendOtp(String identifier) {
        String otp = String.format("%04d", random.nextInt(10000));
        pendingOtp.put(identifier, otp);
        System.out.println("[SIMULATED] OTP sent to " + identifier + ": " + otp);
        return otp;
    }

    public boolean verifyOtp(String identifier, String otp) {
        String expected = pendingOtp.get(identifier);
        if (expected != null && expected.equals(otp)) {
            pendingOtp.remove(identifier);
            return true;
        }
        return false;
    }

    public Employee registerEmployee(String name, String email, String phone, String password, String address) {
        Employee e = new Employee(name, email, phone, password, address);
        employees.add(e);
        return e;
    }

    public Admin registerAdmin(String name, String email, String phone, String password) {
        Admin a = new Admin(name, email, phone, password);
        admins.add(a);
        return a;
    }

    public Employee employeeLogin(String emailOrPhone, String password) {
        for (Employee e : employees) {
            if (e.isDeleted()) continue;
            if ((e.getEmail().equalsIgnoreCase(emailOrPhone) || e.getPhone().equals(emailOrPhone))
                    && e.getPassword().equals(password)) {
                return e;
            }
        }
        return null;
    }

    public Admin adminLogin(String emailOrPhone, String password) {
        for (Admin a : admins) {
            if ((a.getEmail().equalsIgnoreCase(emailOrPhone) || a.getPhone().equals(emailOrPhone))
                    && a.getPassword().equals(password)) {
                return a;
            }
        }
        return null;
    }

    // Find employee by id
    public Employee findEmployeeById(int id) {
        for (Employee e : employees) if (e.getId() == id && !e.isDeleted()) return e;
        return null;
    }

    // Find employee by exact name
    public Employee findEmployeeByName(String name) {
        for (Employee e : employees) if (e.getName().equalsIgnoreCase(name) && !e.isDeleted()) return e;
        return null;
    }

    public boolean forgotPasswordProcess(String identifier) {
        // identifier can be email or phone
        for (Employee e : employees) {
            if (e.getEmail().equalsIgnoreCase(identifier) || e.getPhone().equals(identifier)) {
                String otp = sendOtp(identifier);
                System.out.println("An OTP has been sent to your identifier. Please verify to reset password.");
                return true;
            }
        }
        for (Admin a : admins) {
            if (a.getEmail().equalsIgnoreCase(identifier) || a.getPhone().equals(identifier)) {
                String otp = sendOtp(identifier);
                System.out.println("An OTP has been sent to your identifier. Please verify to reset password.");
                return true;
            }
        }
        return false;
    }

    // reset password after OTP verified
    public boolean resetEmployeePassword(String identifier, String newPassword) {
        for (Employee e : employees) {
            if (e.getEmail().equalsIgnoreCase(identifier) || e.getPhone().equals(identifier)) {
                e.setPassword(newPassword);
                return true;
            }
        }
        for (Admin a : admins) {
            if (a.getEmail().equalsIgnoreCase(identifier) || a.getPhone().equals(identifier)) {
                // Admin password reset: reflection not allowed; ideally implement Admin setters.
                // For minimal app, we won't support resetting admin password via this method.
                return false;
            }
        }
        return false;
    }
}
