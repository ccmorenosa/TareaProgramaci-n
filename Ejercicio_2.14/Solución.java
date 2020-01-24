public class Solución{

    public static double eq(double l1, double l2, double g, double a){
        double A=l2*(Math.cos(Math.PI-g-a))/(Math.sin(Math.PI-g-a)*Math.sin(Math.PI-g-a));
        double B=l1*(Math.cos(a))/(Math.sin(a)*Math.sin(a));
        return A-B;
    }

    public static double deq(double l1, double l2, double g, double a){
        double A=l2*(1+Math.cos(Math.PI-g-a))/(Math.sin(Math.PI-g-a)*Math.sin(Math.PI-g-a)*Math.sin(Math.PI-g-a));
        double B=l1*(1+Math.cos(a))/(Math.sin(a)*Math.sin(a)*Math.sin(a));
        return A+B;
    }

    public static double L(double l1, double l2, double g, double ai){
        double a=Newton(l1,l2,g,ai);
        double A=l2/(Math.sin(Math.PI-g-a));
        double B=l1/(Math.sin(a));
        return A+B;
    }

    public static double Newton(double l1, double l2, double g, double ai){
        double r=ai;
        double h=1e-10;
        while(Math.abs(eq(l1,l2,g,r))>=h){
            r-=eq(l1,l2,g,r)/deq(l1,l2,g,r);
        }
        return r;        
    }
    
    public static void main(String[] args){
        double l1=8;
        double l2=10;
        double g=3*Math.PI/5;
        double ai=Math.PI/5;
        System.out.printf("alfa= %.14f%n",Newton(l1,l2,g,ai));
        System.out.printf("L= %.4f%n",L(l1,l2,g,ai));
    }
}
