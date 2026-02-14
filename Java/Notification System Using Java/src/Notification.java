/// abstract class for notification
abstract class Notification {

    private double rainfall;
    private double temperature;

    Notification(double rainfall, double temperature) {
        this.rainfall = rainfall;
        this.temperature = temperature;
    }
    public double get_rainfall() {
        return this.rainfall;
    }
    public double get_temperature() {
        return this.temperature;
    }

    public abstract void alert();

    public void forcats(){
        System.out.println("Temp : " + this.temperature);
        System.out.println("Rainfall : " + this.rainfall+"\n");
    }
}