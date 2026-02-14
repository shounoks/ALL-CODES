import java.util.Scanner;

/// main class
public class F_Notification {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Rainfall: ");
        double rainfall = sc.nextDouble();

        System.out.print("Enter Temperature: ");
        double temperature = sc.nextDouble();

        String[] user_sub = { null, "Email", "SMS", null, "SMS", "SMS", null, null};

        Notification_Factory nf = new Notification_Factory();

        System.out.print("\n");
        for(String sub : user_sub){
            Notification n = nf.create(sub, rainfall, temperature);
            n.alert();
        }

    }
}
