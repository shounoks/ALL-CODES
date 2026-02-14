class Notification_Factory implements Factory{

    public Notification create(String name, double rainfall, double temperature){
        if(name == null){
            return new Push_Notification(rainfall, temperature);
        }
        if(name.equalsIgnoreCase("Email")){
            return new Email_Notification(rainfall, temperature);

        }else if(name.equalsIgnoreCase("SMS")){
            return new SMS_Notification(rainfall, temperature);
        }
        return new Push_Notification(rainfall, temperature);
    }
}
