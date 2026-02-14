///  push mean user using app
class Push_Notification extends Notification{

    @Override
    public void alert(){
        Check_Up bol = new Check_Up(get_rainfall(), get_temperature());

        if(bol.isAlert()){
            System.out.println("##Via Push##\nWater level is not Normal");
            forcats();
        }else{
            System.out.println("##Via Push##\nWater level is Normal");
            forcats();
        }
    }

    Push_Notification(double rainfall, double temperature) {
        super(rainfall, temperature);
    }
}
