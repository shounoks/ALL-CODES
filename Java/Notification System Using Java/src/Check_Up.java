import java.util.*;

///  logic checker class
class Check_Up{
    private static double alpha = 0.5;
    private static double beta = 0.01;
    private static double gamma = 5;

    private static double convention_factor = 0.7;
    private static double threshold = 19;

    private double rainfall;
    private double temperature;


    /// taken from privious project
    private double calculate(){
        return ((alpha * rainfall) + (beta * temperature) + gamma) *  convention_factor;
    }

    Check_Up(double rainfall, double temperature){
        this.rainfall = rainfall;
        this.temperature = temperature;
    }

    Boolean isAlert(){
        return calculate() > threshold;
    }
}
