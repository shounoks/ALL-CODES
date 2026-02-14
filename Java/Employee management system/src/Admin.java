public class Admin {
    private static int NEXT_ID = 1;

    private final int id;
    private String name;
    private String email;
    private String phone;
    private String password;

    public Admin(String name, String email, String phone, String password) {
        this.id = NEXT_ID++;
        this.name = name;
        this.email = email;
        this.phone = phone;
        this.password = password;
    }

    public int getId() { return id; }
    public String getName() { return name; }
    public String getEmail() { return email; }
    public String getPhone() { return phone; }
    public String getPassword() { return password; }

    public String info() {
        return String.format("Admin ID:%d  Name:%s  Email:%s  Phone:%s", id, name, email, phone);
    }
}
