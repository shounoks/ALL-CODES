///  for email subscription
class Email_Notification extends Notification{
    @Override
    public void alert(){
        Check_Up bol = new Check_Up(get_rainfall(), get_temperature());

        if(bol.isAlert()){
            System.out.println("##Via Email##\nWater level is not Normal");
            forcats();
        }else{
            System.out.println("##Via Email##\nWater level is Normal");
            forcats();
        }
    }

    Email_Notification(double rainfall, double temperature) {
        super(rainfall, temperature);
    }
}