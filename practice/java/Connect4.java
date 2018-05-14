import java.awt.Color;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author SIDHANT
 */
public class Connect4 extends javax.swing.JFrame {
    public static boolean playerTurn = true;
    public static boolean playerWon = false;
    public static boolean computerWon = false;
    public static boolean Draw = false;

    /**
     * Creates new form Connect4
     */
    public Connect4() {
        initComponents();
    }

    public void checkforWin () 
    {
        
        if (p1.getText().equals("R") && p2.getText().equals("R") && p3.getText().equals("R") && p4.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
       
        
        
        
        if (p2.getText().equals("R") && p3.getText().equals("R") && p4.getText().equals("R") && p5.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p3.getText().equals("R") && p4.getText().equals("R") && p5.getText().equals("R") && p6.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p7.getText().equals("R") && p8.getText().equals("R") && p9.getText().equals("R") && p10.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        if (p8.getText().equals("R") && p9.getText().equals("R") && p10.getText().equals("R") && p11.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p9.getText().equals("R") && p10.getText().equals("R") && p11.getText().equals("R") && p12.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p13.getText().equals("R") && p14.getText().equals("R") && p15.getText().equals("R") && p16.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p14.getText().equals("R") && p15.getText().equals("R") && p16.getText().equals("R") && p17.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        if (p15.getText().equals("R") && p16.getText().equals("R") && p17.getText().equals("R") && p18.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        if (p19.getText().equals("R") && p20.getText().equals("R") && p21.getText().equals("R") && p22.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p20.getText().equals("R") && p21.getText().equals("R") && p22.getText().equals("R") && p23.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p21.getText().equals("R") && p22.getText().equals("R") && p23.getText().equals("R") && p24.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p25.getText().equals("R") && p26.getText().equals("R") && p27.getText().equals("R") && p28.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p26.getText().equals("R") && p27.getText().equals("R") && p28.getText().equals("R") && p29.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p27.getText().equals("R") && p28.getText().equals("R") && p29.getText().equals("R") && p30.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
       
        
        if (p31.getText().equals("R") && p32.getText().equals("R") && p33.getText().equals("R") && p34.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p32.getText().equals("R") && p33.getText().equals("R") && p34.getText().equals("R") && p35.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p33.getText().equals("R") && p34.getText().equals("R") && p35.getText().equals("R") && p36.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        
        if (p1.getText().equals("R") && p7.getText().equals("R") && p13.getText().equals("R") && p19.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p7.getText().equals("R") && p13.getText().equals("R") && p19.getText().equals("R") && p25.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p13.getText().equals("R") && p19.getText().equals("R") && p25.getText().equals("R") && p31.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        
        if (p2.getText().equals("R") && p8.getText().equals("R") && p14.getText().equals("R") && p20.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p8.getText().equals("R") && p14.getText().equals("R") && p20.getText().equals("R") && p26.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p14.getText().equals("R") && p20.getText().equals("R") && p26.getText().equals("R") && p32.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        
        if (p3.getText().equals("R") && p9.getText().equals("R") && p15.getText().equals("R") && p21.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p9.getText().equals("R") && p15.getText().equals("R") && p21.getText().equals("R") && p27.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p15.getText().equals("R") && p21.getText().equals("R") && p27.getText().equals("R") && p33.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        
        if (p4.getText().equals("R") && p10.getText().equals("R") && p16.getText().equals("R") && p22.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p10.getText().equals("R") && p16.getText().equals("R") && p22.getText().equals("R") && p28.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p16.getText().equals("R") && p22.getText().equals("R") && p28.getText().equals("R") && p34.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        
        if (p5.getText().equals("R") && p11.getText().equals("R") && p17.getText().equals("R") && p23.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p11.getText().equals("R") && p17.getText().equals("R") && p23.getText().equals("R") && p29.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
           if (p17.getText().equals("R") && p23.getText().equals("R") && p29.getText().equals("R") && p35.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        
        if (p6.getText().equals("R") && p12.getText().equals("R") && p18.getText().equals("R") && p24.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p12.getText().equals("R") && p18.getText().equals("R") && p24.getText().equals("R") && p30.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p18.getText().equals("R") && p24.getText().equals("R") && p30.getText().equals("R") && p36.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
         
        
        if (p19.getText().equals("R") && p14.getText().equals("R") && p9.getText().equals("R") && p4.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
           if (p25.getText().equals("R") && p20.getText().equals("R") && p15.getText().equals("R") && p10.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p20.getText().equals("R") && p15.getText().equals("R") && p10.getText().equals("R") && p5.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p31.getText().equals("R") && p26.getText().equals("R") && p21.getText().equals("R") && p16.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p26.getText().equals("R") && p21.getText().equals("R") && p16.getText().equals("R") && p11.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p21.getText().equals("R") && p16.getText().equals("R") && p11.getText().equals("R") && p6.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
           if (p33.getText().equals("R") && p28.getText().equals("R") && p23.getText().equals("R") && p18.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p32.getText().equals("R") && p27.getText().equals("R") && p22.getText().equals("R") && p17.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p27.getText().equals("R") && p22.getText().equals("R") && p17.getText().equals("R") && p12.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
       
        
        if (p24.getText().equals("R") && p17.getText().equals("R") && p10.getText().equals("R") && p3.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p30.getText().equals("R") && p23.getText().equals("R") && p16.getText().equals("R") && p9.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
           if (p23.getText().equals("R") && p16.getText().equals("R") && p9.getText().equals("R") && p2.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p36.getText().equals("R") && p29.getText().equals("R") && p22.getText().equals("R") && p15.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
    
        
           if (p29.getText().equals("R") && p22.getText().equals("R") && p15.getText().equals("R") && p8.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p22.getText().equals("R") && p15.getText().equals("R") && p8.getText().equals("R") && p1.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        if (p35.getText().equals("R") && p28.getText().equals("R") && p21.getText().equals("R") && p14.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
    
        
           if (p28.getText().equals("R") && p21.getText().equals("R") && p14.getText().equals("R") && p7.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
        
        
        if (p34.getText().equals("R") && p27.getText().equals("R") && p20.getText().equals("R") && p13.getText().equals("R"))
        {
            playerWon  = true;
            computerWon = false;
            out.setText("RED WON!!");
        }
    
        
    
    
       
        
       if (p1.getText().equals("Y") && p2.getText().equals("Y") && p3.getText().equals("Y") && p4.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
       
        
        if (p2.getText().equals("Y") && p3.getText().equals("Y") && p4.getText().equals("Y") && p5.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p3.getText().equals("Y") && p4.getText().equals("Y") && p5.getText().equals("Y") && p6.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p7.getText().equals("Y") && p8.getText().equals("Y") && p9.getText().equals("Y") && p10.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        if (p8.getText().equals("Y") && p9.getText().equals("Y") && p10.getText().equals("Y") && p11.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p9.getText().equals("Y") && p10.getText().equals("Y") && p11.getText().equals("Y") && p12.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p13.getText().equals("Y") && p14.getText().equals("Y") && p15.getText().equals("Y") && p16.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p14.getText().equals("Y") && p15.getText().equals("Y") && p16.getText().equals("Y") && p17.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        if (p15.getText().equals("Y") && p16.getText().equals("Y") && p17.getText().equals("Y") && p18.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p19.getText().equals("Y") && p20.getText().equals("Y") && p21.getText().equals("Y") && p22.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p20.getText().equals("Y") && p21.getText().equals("Y") && p22.getText().equals("Y") && p23.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p21.getText().equals("Y") && p22.getText().equals("Y") && p23.getText().equals("Y") && p24.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p25.getText().equals("Y") && p26.getText().equals("Y") && p27.getText().equals("Y") && p28.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p26.getText().equals("Y") && p27.getText().equals("Y") && p28.getText().equals("Y") && p29.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p27.getText().equals("Y") && p28.getText().equals("Y") && p29.getText().equals("Y") && p30.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p31.getText().equals("Y") && p32.getText().equals("Y") && p33.getText().equals("Y") && p34.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p32.getText().equals("Y") && p33.getText().equals("Y") && p34.getText().equals("Y") && p35.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p33.getText().equals("Y") && p34.getText().equals("Y") && p35.getText().equals("Y") && p36.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
       
        
        if (p1.getText().equals("Y") && p7.getText().equals("Y") && p13.getText().equals("Y") && p19.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p7.getText().equals("Y") && p13.getText().equals("Y") && p19.getText().equals("Y") && p25.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p13.getText().equals("Y") && p19.getText().equals("Y") && p25.getText().equals("Y") && p31.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
      
        
        if (p2.getText().equals("Y") && p8.getText().equals("Y") && p14.getText().equals("Y") && p20.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p8.getText().equals("Y") && p14.getText().equals("Y") && p20.getText().equals("Y") && p26.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
       
        
        if (p14.getText().equals("Y") && p20.getText().equals("Y") && p26.getText().equals("Y") && p32.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p3.getText().equals("Y") && p9.getText().equals("Y") && p15.getText().equals("Y") && p21.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
         
        
        if (p9.getText().equals("Y") && p15.getText().equals("Y") && p21.getText().equals("Y") && p27.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        if (p15.getText().equals("Y") && p21.getText().equals("Y") && p27.getText().equals("Y") && p33.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p4.getText().equals("Y") && p10.getText().equals("Y") && p16.getText().equals("Y") && p22.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p10.getText().equals("Y") && p16.getText().equals("Y") && p22.getText().equals("Y") && p28.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p16.getText().equals("Y") && p22.getText().equals("Y") && p28.getText().equals("Y") && p34.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        if (p5.getText().equals("Y") && p11.getText().equals("Y") && p17.getText().equals("Y") && p23.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p11.getText().equals("Y") && p17.getText().equals("Y") && p23.getText().equals("Y") && p29.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p17.getText().equals("Y") && p23.getText().equals("Y") && p29.getText().equals("Y") && p35.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p6.getText().equals("Y") && p12.getText().equals("Y") && p18.getText().equals("Y") && p24.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p12.getText().equals("Y") && p18.getText().equals("Y") && p24.getText().equals("Y") && p30.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p18.getText().equals("Y") && p24.getText().equals("Y") && p30.getText().equals("Y") && p36.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p19.getText().equals("Y") && p14.getText().equals("Y") && p9.getText().equals("Y") && p4.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p25.getText().equals("Y") && p20.getText().equals("Y") && p15.getText().equals("Y") && p10.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p20.getText().equals("Y") && p15.getText().equals("Y") && p10.getText().equals("Y") && p5.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p31.getText().equals("Y") && p26.getText().equals("Y") && p21.getText().equals("Y") && p16.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
      
        
        if (p26.getText().equals("Y") && p21.getText().equals("Y") && p16.getText().equals("Y") && p11.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p21.getText().equals("Y") && p16.getText().equals("Y") && p11.getText().equals("Y") && p6.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p33.getText().equals("Y") && p28.getText().equals("Y") && p23.getText().equals("Y") && p18.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p32.getText().equals("Y") && p27.getText().equals("Y") && p22.getText().equals("Y") && p17.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        if (p27.getText().equals("Y") && p22.getText().equals("Y") && p17.getText().equals("Y") && p12.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        if (p24.getText().equals("Y") && p17.getText().equals("Y") && p10.getText().equals("Y") && p3.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p30.getText().equals("Y") && p23.getText().equals("Y") && p16.getText().equals("Y") && p9.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p23.getText().equals("Y") && p16.getText().equals("Y") && p9.getText().equals("Y") && p2.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p36.getText().equals("Y") && p29.getText().equals("Y") && p22.getText().equals("Y") && p15.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p29.getText().equals("Y") && p22.getText().equals("Y") && p15.getText().equals("Y") && p8.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p22.getText().equals("Y") && p15.getText().equals("Y") && p8.getText().equals("Y") && p1.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        if (p35.getText().equals("Y") && p28.getText().equals("Y") && p21.getText().equals("Y") && p14.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        
        
        if (p28.getText().equals("Y") && p21.getText().equals("Y") && p14.getText().equals("Y") && p7.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
        
        if (p34.getText().equals("Y") && p27.getText().equals("Y") && p20.getText().equals("Y") && p13.getText().equals("Y"))
        {
            playerWon  = false;
            computerWon = true;
            out.setText("YELLOW WON!!");
        }
         
    }      
            
    public void checkforDraw()
    {
            if ( 
                    ! (p1.getText().equals("")) &&
                    ! (p2.getText().equals("")) &&
                    ! (p3.getText().equals("")) &&
                    ! (p4.getText().equals("")) &&
                    ! (p5.getText().equals("")) &&
                    ! (p6.getText().equals("")) &&
                    ! (p7.getText().equals("")) &&
                    ! (p8.getText().equals("")) &&
                    ! (p9.getText().equals("")) &&
                    ! (p10.getText().equals("")) &&
                    ! (p11.getText().equals("")) &&
                    ! (p12.getText().equals("")) &&
                    ! (p13.getText().equals("")) &&
                    ! (p14.getText().equals("")) &&
                    ! (p15.getText().equals("")) &&
                    ! (p16.getText().equals("")) &&
                    ! (p17.getText().equals("")) &&
                    ! (p18.getText().equals("")) &&
                    ! (p19.getText().equals("")) &&
                    ! (p20.getText().equals("")) &&
                    ! (p21.getText().equals("")) &&
                    ! (p22.getText().equals("")) &&
                    ! (p23.getText().equals("")) &&
                    ! (p24.getText().equals("")) &&
                    ! (p25.getText().equals("")) &&
                    ! (p26.getText().equals("")) &&
                    ! (p27.getText().equals("")) &&
                    ! (p28.getText().equals("")) &&
                    ! (p29.getText().equals("")) &&
                    ! (p30.getText().equals("")) &&
                    ! (p31.getText().equals("")) &&
                    ! (p32.getText().equals("")) &&
                    ! (p33.getText().equals("")) &&
                    ! (p34.getText().equals("")) &&
                    ! (p35.getText().equals("")) &&
                    ! (p36.getText().equals(""))  
                    ) 
            {
                Turner.setText("IT'S A DRAW !!");
                Draw = true;
            }
    }
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">                          
    private void initComponents() {

        p1 = new javax.swing.JTextField();
        p2 = new javax.swing.JTextField();
        p3 = new javax.swing.JTextField();
        p4 = new javax.swing.JTextField();
        p5 = new javax.swing.JTextField();
        p6 = new javax.swing.JTextField();
        p7 = new javax.swing.JTextField();
        p12 = new javax.swing.JTextField();
        p10 = new javax.swing.JTextField();
        p11 = new javax.swing.JTextField();
        p8 = new javax.swing.JTextField();
        p9 = new javax.swing.JTextField();
        p21 = new javax.swing.JTextField();
        p20 = new javax.swing.JTextField();
        p13 = new javax.swing.JTextField();
        p23 = new javax.swing.JTextField();
        p24 = new javax.swing.JTextField();
        p22 = new javax.swing.JTextField();
        p18 = new javax.swing.JTextField();
        p19 = new javax.swing.JTextField();
        p16 = new javax.swing.JTextField();
        p17 = new javax.swing.JTextField();
        p14 = new javax.swing.JTextField();
        p15 = new javax.swing.JTextField();
        p33 = new javax.swing.JTextField();
        p32 = new javax.swing.JTextField();
        p27 = new javax.swing.JTextField();
        p25 = new javax.swing.JTextField();
        p35 = new javax.swing.JTextField();
        p36 = new javax.swing.JTextField();
        p34 = new javax.swing.JTextField();
        p30 = new javax.swing.JTextField();
        p31 = new javax.swing.JTextField();
        p28 = new javax.swing.JTextField();
        p26 = new javax.swing.JTextField();
        p29 = new javax.swing.JTextField();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jButton4 = new javax.swing.JButton();
        jButton5 = new javax.swing.JButton();
        jButton6 = new javax.swing.JButton();
        out = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        jButton7 = new javax.swing.JButton();
        jButton8 = new javax.swing.JButton();
        Turner = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        p1.setEditable(false);
        p1.setBackground(new java.awt.Color(255, 255, 255));
        p1.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p1.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p2.setEditable(false);
        p2.setBackground(new java.awt.Color(255, 255, 255));
        p2.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p2.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p3.setEditable(false);
        p3.setBackground(new java.awt.Color(255, 255, 255));
        p3.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p3.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p4.setEditable(false);
        p4.setBackground(new java.awt.Color(255, 255, 255));
        p4.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p4.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p5.setEditable(false);
        p5.setBackground(new java.awt.Color(255, 255, 255));
        p5.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p5.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p6.setEditable(false);
        p6.setBackground(new java.awt.Color(255, 255, 255));
        p6.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p6.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p7.setEditable(false);
        p7.setBackground(new java.awt.Color(255, 255, 255));
        p7.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p7.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p12.setEditable(false);
        p12.setBackground(new java.awt.Color(255, 255, 255));
        p12.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p12.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p10.setEditable(false);
        p10.setBackground(new java.awt.Color(255, 255, 255));
        p10.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p10.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p11.setEditable(false);
        p11.setBackground(new java.awt.Color(255, 255, 255));
        p11.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p11.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p8.setEditable(false);
        p8.setBackground(new java.awt.Color(255, 255, 255));
        p8.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p8.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p9.setEditable(false);
        p9.setBackground(new java.awt.Color(255, 255, 255));
        p9.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p9.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p21.setEditable(false);
        p21.setBackground(new java.awt.Color(255, 255, 255));
        p21.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p21.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p20.setEditable(false);
        p20.setBackground(new java.awt.Color(255, 255, 255));
        p20.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p20.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p13.setEditable(false);
        p13.setBackground(new java.awt.Color(255, 255, 255));
        p13.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p13.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p23.setEditable(false);
        p23.setBackground(new java.awt.Color(255, 255, 255));
        p23.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p23.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p24.setEditable(false);
        p24.setBackground(new java.awt.Color(255, 255, 255));
        p24.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p24.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p22.setEditable(false);
        p22.setBackground(new java.awt.Color(255, 255, 255));
        p22.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p22.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p18.setEditable(false);
        p18.setBackground(new java.awt.Color(255, 255, 255));
        p18.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p18.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p19.setEditable(false);
        p19.setBackground(new java.awt.Color(255, 255, 255));
        p19.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p19.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        p19.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                p19ActionPerformed(evt);
            }
        });

        p16.setEditable(false);
        p16.setBackground(new java.awt.Color(255, 255, 255));
        p16.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p16.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p17.setEditable(false);
        p17.setBackground(new java.awt.Color(255, 255, 255));
        p17.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p17.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p14.setEditable(false);
        p14.setBackground(new java.awt.Color(255, 255, 255));
        p14.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p14.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p15.setEditable(false);
        p15.setBackground(new java.awt.Color(255, 255, 255));
        p15.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p15.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p33.setEditable(false);
        p33.setBackground(new java.awt.Color(255, 255, 255));
        p33.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p33.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p32.setEditable(false);
        p32.setBackground(new java.awt.Color(255, 255, 255));
        p32.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p32.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p27.setEditable(false);
        p27.setBackground(new java.awt.Color(255, 255, 255));
        p27.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p27.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p25.setEditable(false);
        p25.setBackground(new java.awt.Color(255, 255, 255));
        p25.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p25.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p35.setEditable(false);
        p35.setBackground(new java.awt.Color(255, 255, 255));
        p35.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p35.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p36.setEditable(false);
        p36.setBackground(new java.awt.Color(255, 255, 255));
        p36.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p36.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p34.setEditable(false);
        p34.setBackground(new java.awt.Color(255, 255, 255));
        p34.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p34.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p30.setEditable(false);
        p30.setBackground(new java.awt.Color(255, 255, 255));
        p30.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p30.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p31.setEditable(false);
        p31.setBackground(new java.awt.Color(255, 255, 255));
        p31.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p31.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p28.setEditable(false);
        p28.setBackground(new java.awt.Color(255, 255, 255));
        p28.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p28.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p26.setEditable(false);
        p26.setBackground(new java.awt.Color(255, 255, 255));
        p26.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p26.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        p29.setEditable(false);
        p29.setBackground(new java.awt.Color(255, 255, 255));
        p29.setFont(new java.awt.Font("a song for jennifer", 0, 48)); // NOI18N
        p29.setHorizontalAlignment(javax.swing.JTextField.CENTER);

        jButton1.setText("1");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("2");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setText("3");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jButton4.setText("4");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        jButton5.setText("5");
        jButton5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton5ActionPerformed(evt);
            }
        });

        jButton6.setText("6");
        jButton6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton6ActionPerformed(evt);
            }
        });

        out.setEditable(false);
        out.setBackground(new java.awt.Color(204, 204, 204));
        out.setFont(new java.awt.Font("Eras Light ITC", 2, 18)); // NOI18N
        out.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        out.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(51, 51, 255), 1, true));

        jLabel1.setFont(new java.awt.Font("SimHei", 3, 30)); // NOI18N
        jLabel1.setText("CONNECT 4");

        jButton7.setText("NEW GAME");
        jButton7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton7ActionPerformed(evt);
            }
        });

        jButton8.setText("EXIT");
        jButton8.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton8ActionPerformed(evt);
            }
        });

        Turner.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        Turner.setText("RED STARTS (PLAYER 1)");
        Turner.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(out))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(32, 32, 32)
                        .addComponent(jButton8)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jButton7)
                        .addGap(14, 14, 14)
                        .addComponent(Turner, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(p25, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p26, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p27, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p28, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p29, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p30, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(p19, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p20, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p21, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p22, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p23, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p24, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(p13, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p14, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p15, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p16, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p17, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p18, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(p7, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p8, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p9, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p10, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p11, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p12, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(p1, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p2, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p3, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p4, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p5, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(p6, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(p31, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(10, 10, 10)
                                        .addComponent(jButton1)))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(10, 10, 10)
                                        .addComponent(jButton2))
                                    .addComponent(p32, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(10, 10, 10)
                                        .addComponent(jButton3))
                                    .addComponent(p33, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(10, 10, 10)
                                        .addComponent(jButton4))
                                    .addComponent(p34, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(10, 10, 10)
                                        .addComponent(jButton5))
                                    .addComponent(p35, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGap(10, 10, 10)
                                        .addComponent(jButton6))
                                    .addComponent(p36, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))))
                        .addGap(53, 53, 53)))
                .addContainerGap())
            .addGroup(layout.createSequentialGroup()
                .addGap(183, 183, 183)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 218, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(10, 10, 10)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(p1, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p2, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p3, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p4, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p5, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p6, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(p7, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p8, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p9, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p10, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p11, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p12, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(p13, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p14, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p15, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p16, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p17, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p18, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(p19, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p20, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p21, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p22, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p23, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p24, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(p25, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p26, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p27, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p28, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p29, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p30, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(p31, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p32, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p33, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p34, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p35, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p36, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton2)
                    .addComponent(jButton3)
                    .addComponent(jButton4)
                    .addComponent(jButton5)
                    .addComponent(jButton6))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton7, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jButton8, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(Turner, javax.swing.GroupLayout.PREFERRED_SIZE, 29, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(out, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>                        

    private void p19ActionPerformed(java.awt.event.ActionEvent evt) {                                    
        // TODO add your handling code here:
    }                                   

    @SuppressWarnings("empty-statement")
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {                                         
      
        if (playerWon || computerWon || Draw)
        {
            out.setText("CLICK NEW GAME TO PLAY AGAIN");
        }
        else {
        if (playerTurn == true)
        {
            
            Turner.setText("YELLOW'S TURN (Player 2)");
            if (p31.getText().equals(""))
            {
                p31.setText("R");
                p31.setBackground(Color.red);
                checkforWin();
                checkforDraw();
                playerTurn = false;
            }
            else
            {
                    if (p25.getText().equals(""))
                {
                        p25.setText("R");
                        p25.setBackground(Color.red);
                        checkforWin();
                        checkforDraw();
                        playerTurn = false;
                }
           else
                        {
                                    if (p19.getText().equals(""))
                                {
                                        p19.setText("R");
                                        p19.setBackground(Color.red);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = false;
                                }
           else
                        {
                                if (p13.getText().equals(""))
                             {
                                    p13.setText("R");
                                    p13.setBackground(Color.red);
                                    checkforWin();
                                    checkforDraw();
                                    playerTurn = false;
                             }
            else
                        {
                                if (p7.getText().equals(""))
                                     {
                                          p7.setText("R");
                                          p7.setBackground(Color.red);
                                          checkforWin();
                                          checkforDraw();
                                          playerTurn = false;
                                      }
                    
            else
                        {
                                    if (p1.getText().equals(""))
                                      {
                                        p1.setText("R");
                                        p1.setBackground(Color.red);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = false;
                                      }
                else {JOptionPane.showMessageDialog(this, "COLUMN IS FILLED CHOOSE ANOTHER", "ERROR", 2);}
                         }
                        
                         }
                            
                         }
            
                         } 
            
                         }
        
                         }
        else 
        {
             Turner.setText("RED'S TURN (Player 1)");
        {
            if (p31.getText().equals(""))
            {
                p31.setText("Y");
                p31.setBackground(Color.yellow);
                checkforWin();
                checkforDraw();
                playerTurn = true;
            }
            else
            
                    if (p25.getText().equals(""))
                {
                        p25.setText("Y");
                        p25.setBackground(Color.yellow);
                        checkforWin();
                        checkforDraw();
                        playerTurn = true;
                }
           else
                        {
                                    if (p19.getText().equals(""))
                                {
                                        p19.setText("Y");
                                        p19.setBackground(Color.yellow);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = true;
                                }
           else
                        {
                                if (p13.getText().equals(""))
                             {
                                    p13.setText("Y");
                                    p13.setBackground(Color.yellow);
                                    checkforWin();
                                    checkforDraw();
                                    playerTurn = true;
                             }
            else
                        {
                                if (p7.getText().equals(""))
                                     {
                                          p7.setText("Y");
                                          p7.setBackground(Color.yellow);
                                          checkforWin();
                                          checkforDraw();
                                          playerTurn = true;
                                      }
                    
            else
                        {
                                    if (p1.getText().equals(""))
                                      {
                                        p1.setText("Y");
                                        p1.setBackground(Color.yellow);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = true;
                                      }
                                    else {JOptionPane.showMessageDialog(this, "COLUMN IS FILLED CHOOSE ANOTHER", "ERROR", 2);}
                         }
                        
                         }
                            
                         }
            
                         } 
            
                         }
        
                         }
        }
    }                                        

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {                                         
        // TODO add your handling code here:
       if (playerWon==true || computerWon== true || Draw== true)
        {
            out.setText("CLICK NEW GAME TO PLAY AGAIN");
        }
        else {
        if (playerTurn == true)
        {
            Turner.setText("YELLOW'S TURN (Player 2)");
            if (p32.getText().equals(""))
            {
                p32.setText("R");
                p32.setBackground(Color.red);
                checkforWin();
                checkforDraw();
                playerTurn = false;
            }
            else
            {
                    if (p26.getText().equals(""))
                {
                        p26.setText("R");
                        p26.setBackground(Color.red);
                        checkforWin();
                        checkforDraw();
                        playerTurn = false;
                }
           else
                        {
                                    if (p20.getText().equals(""))
                                {
                                        p20.setText("R");
                                        p20.setBackground(Color.red);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = false;
                                }
           else
                        {
                                if (p14.getText().equals(""))
                             {
                                    p14.setText("R");
                                    p14.setBackground(Color.red);
                                    checkforWin();
                                    checkforDraw();
                                    playerTurn = false;
                             }
            else
                        {
                                if (p8.getText().equals(""))
                                     {
                                          p8.setText("R");
                                          p8.setBackground(Color.red);
                                          checkforWin();
                                          checkforDraw();
                                          playerTurn = false;
                                      }
                    
            else
                        {
                            
                                    if (p2.getText().equals(""))
                                      {
                                        p2.setText("R");
                                        p2.setBackground(Color.red);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = false;
                                      }
                                    else {JOptionPane.showMessageDialog(this, "COLUMN IS FILLED CHOOSE ANOTHER", "ERROR", 2);}
                         }
                        
                         }
                            
                         }
            
                         } 
            
                         }
        
                         }
        else 
        {
             Turner.setText("RED'S TURN (Player 1)");
        {
            if (p32.getText().equals(""))
            {
                p32.setText("Y");
                p32.setBackground(Color.yellow);
                checkforWin();
                checkforDraw();
                playerTurn = true;
            }
            else
            
                    if (p26.getText().equals(""))
                {
                        p26.setText("Y");
                        p26.setBackground(Color.yellow);
                        checkforWin();
                        checkforDraw();
                        playerTurn = true;
                }
           else
                        {
                                    if (p20.getText().equals(""))
                                {
                                        p20.setText("Y");
                                        p20.setBackground(Color.yellow);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = true;
                                }
           else
                        {
                                if (p14.getText().equals(""))
                             {
                                    p14.setText("Y");
                                    p14.setBackground(Color.yellow);
                                    checkforWin();
                                    checkforDraw();
                                    playerTurn = true;
                             }
            else
                        {
                                if (p8.getText().equals(""))
                                     {
                                          p8.setText("Y");
                                          p8.setBackground(Color.yellow);
                                          checkforWin();
                                          checkforDraw();
                                          playerTurn = true;
                                      }
                    
            else
                        {
                                    if (p2.getText().equals(""))
                                      {
                                        p2.setText("Y");
                                        p2.setBackground(Color.yellow);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = true;
                                      }
                                    else {JOptionPane.showMessageDialog(this, "COLUMN IS FILLED CHOOSE ANOTHER", "ERROR", 2);}
                         }
                                
                         } 
                                
                         }
                                    
                         } 
            
                         }
                         }
        }
    }                                        

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {                                         
        // TODO add your handling code here:
       if (playerWon==true || computerWon== true || Draw == true)
        {
            out.setText("CLICK NEW GAME TO PLAY AGAIN");
        }
        else {
        if (playerTurn == true)
        {
            Turner.setText("YELLOW'S TURN (Player 2)");
            if (p33.getText().equals(""))
            {
                p33.setText("R");
                p33.setBackground(Color.red);
                checkforWin();
                checkforDraw();
                playerTurn = false;
            }
            else
            {
                    if (p27.getText().equals(""))
                {
                        p27.setText("R");
                        p27.setBackground(Color.red);
                        checkforWin();
                        checkforDraw();
                        playerTurn = false;
                }
           else
                        {
                                    if (p21.getText().equals(""))
                                {
                                        p21.setText("R");
                                        p21.setBackground(Color.red);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = false;
                                }
           else
                        {
                                if (p15.getText().equals(""))
                             {
                                    p15.setText("R");
                                    p15.setBackground(Color.red);
                                    checkforWin();
                                    checkforDraw();
                                    playerTurn = false;
                             }
            else
                        {
                                if (p9.getText().equals(""))
                                     {
                                          p9.setText("R");
                                          p9.setBackground(Color.red);
                                          checkforWin();
                                          checkforDraw();
                                          playerTurn = false;
                                      }
                    
            else
                        {
                                    if (p3.getText().equals(""))
                                      {
                                        p3.setText("R");
                                        p3.setBackground(Color.red);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = false;
                                      }
                                    else {JOptionPane.showMessageDialog(this, "COLUMN IS FILLED CHOOSE ANOTHER", "ERROR", 2);}
                         }
                        
                         }
                            
                         }
            
                         } 
            
                         }
        
                         }
        else 
        {
             Turner.setText("RED'S TURN (Player 1)");
        {
            if (p33.getText().equals(""))
            {
                p33.setText("Y");
                p33.setBackground(Color.yellow);
                checkforWin();
                checkforDraw();
                playerTurn = true;
            }
            else
            
                    if (p27.getText().equals(""))
                {
                        p27.setText("Y");
                        p27.setBackground(Color.yellow);
                        checkforWin();
                        checkforDraw();
                        playerTurn = true;
                }
           else
                        {
                                    if (p21.getText().equals(""))
                                {
                                        p21.setText("Y");
                                        p21.setBackground(Color.yellow);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = true;
                                }
           else
                        {
                                if (p15.getText().equals(""))
                             {
                                    p15.setText("Y");
                                    p15.setBackground(Color.yellow);
                                    checkforWin();
                                    checkforDraw();
                                    playerTurn = true;
                             }
            else
                        {
                                if (p9.getText().equals(""))
                                     {
                                          p9.setText("Y");
                                          p9.setBackground(Color.yellow);
                                          checkforWin();
                                          checkforDraw();
                                          playerTurn = true;
                                      }
                    
            else
                        {
                                    if (p3.getText().equals(""))
                                      {
                                        p3.setText("Y");
                                        p3.setBackground(Color.yellow);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = true;
                                      }
                                    else {JOptionPane.showMessageDialog(this, "COLUMN IS FILLED CHOOSE ANOTHER", "ERROR", 2);}
                         }
                        
                         }
                            
                         }
            
                         } 
            
                         }
        
                         }
        }
    }                                        

    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {                                         
        // TODO add your handling code here:
       if (playerWon==true || computerWon== true || Draw == true)
        {
            out.setText("CLICK NEW GAME TO PLAY AGAIN");
        }
        else{ 
            if (playerTurn == true)
        {
            Turner.setText("YELLOW'S TURN (Player 2)");
            if (p34.getText().equals(""))
            {
                p34.setText("R");
                p34.setBackground(Color.red);
                checkforWin();
                checkforDraw();
                playerTurn = false;
            }
            else
            {
                    if (p28.getText().equals(""))
                {
                        p28.setText("R");
                        p28.setBackground(Color.red);
                        checkforWin();
                        checkforDraw();
                        playerTurn = false;
                }
           else
                        {
                                    if (p22.getText().equals(""))
                                {
                                        p22.setText("R");
                                        p22.setBackground(Color.red);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = false;
                                }
           else
                        {
                                if (p16.getText().equals(""))
                             {
                                    p16.setText("R");
                                    p16.setBackground(Color.red);
                                    checkforWin();
                                    checkforDraw();
                                    playerTurn = false;
                             }
            else
                        {
                                if (p10.getText().equals(""))
                                     {
                                          p10.setText("R");
                                          p10.setBackground(Color.red);
                                          checkforWin();
                                          checkforDraw();
                                          playerTurn = false;
                                      }
                    
            else
                        {
                                    if (p4.getText().equals(""))
                                      {
                                        p4.setText("R");
                                        p4.setBackground(Color.red);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = false;
                                      }
                                    else {JOptionPane.showMessageDialog(this, "COLUMN IS FILLED CHOOSE ANOTHER", "ERROR", 2);}
                         }
                        
                         }
                            
                         }
            
                         } 
            
                         }
        
                         }
        else 
        {
             Turner.setText("RED'S TURN (Player 1)");
        {
            if (p34.getText().equals(""))
            {
                p34.setText("Y");
                p34.setBackground(Color.yellow);
                checkforWin();
                checkforDraw();
                playerTurn = true;
            }
            else
            
                    if (p28.getText().equals(""))
                {
                        p28.setText("Y");
                        p28.setBackground(Color.yellow);
                        checkforWin();
                        checkforDraw();
                        playerTurn = true;
                }
           else
                        {
                                    if (p22.getText().equals(""))
                                {
                                        p22.setText("Y");
                                        p22.setBackground(Color.yellow);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = true;
                                }
           else
                        {
                                if (p16.getText().equals(""))
                             {
                                    p16.setText("Y");
                                    p16.setBackground(Color.yellow);
                                    checkforWin();
                                    checkforDraw();
                                    playerTurn = true;
                             }
            else
                        {
                                if (p10.getText().equals(""))
                                     {
                                          p10.setText("Y");
                                          p10.setBackground(Color.yellow);
                                          checkforWin();
                                          checkforDraw();
                                          playerTurn = true;
                                      }
                    
            else
                        {
                                    if (p4.getText().equals(""))
                                      {
                                        p4.setText("Y");
                                        p4.setBackground(Color.yellow);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = true;
                                      }
                                    else {JOptionPane.showMessageDialog(this, "COLUMN IS FILLED CHOOSE ANOTHER", "ERROR", 2);}
                         }
                        
                         }
                            
                         }
            
                         } 
            
                         }
        
                         }
        }
    }                                        

    private void jButton5ActionPerformed(java.awt.event.ActionEvent evt) {                                         
        // TODO add your handling code here:
       if (playerWon==true || computerWon== true || Draw==true)
        {
            out.setText("CLICK NEW GAME TO PLAY AGAIN");
        }
        else {
        if (playerTurn == true)
        {
            Turner.setText("YELLOW'S TURN (Player 2)");
            if (p35.getText().equals(""))
            {
                p35.setText("R");
                p35.setBackground(Color.red);
                checkforWin();
                checkforDraw();
                playerTurn = false;
            }
            else
            {
                    if (p29.getText().equals(""))
                {
                        p29.setText("R");
                        p29.setBackground(Color.red);
                        checkforWin();
                        checkforDraw();
                        playerTurn = false;
                }
           else
                        {
                                    if (p23.getText().equals(""))
                                {
                                        p23.setText("R");
                                        p23.setBackground(Color.red);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = false;
                                }
           else
                        {
                                if (p17.getText().equals(""))
                             {
                                    p17.setText("R");
                                    p17.setBackground(Color.red);
                                    checkforWin();
                                    checkforDraw();
                                    playerTurn = false;
                             }
            else
                        {
                                if (p11.getText().equals(""))
                                     {
                                          p11.setText("R");
                                          p11.setBackground(Color.red);
                                          checkforWin();
                                          checkforDraw();
                                          playerTurn = false;
                                      }
                    
            else
                        {
                                    if (p5.getText().equals(""))
                                      {
                                        p5.setText("R");
                                        p5.setBackground(Color.red);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = false;
                                      }
                                    else {JOptionPane.showMessageDialog(this, "COLUMN IS FILLED CHOOSE ANOTHER", "ERROR", 2);}
                         }
                        
                         }
                            
                         }
            
                         } 
            
                         }
        
                         }
        else 
        {
             Turner.setText("RED'S TURN (Player 1)");
        {
            if (p35.getText().equals(""))
            {
                p35.setText("Y");
                p35.setBackground(Color.yellow);
                checkforWin();
                checkforDraw();
                playerTurn = true;
            }
            else
            
                    if (p29.getText().equals(""))
                {
                        p29.setText("Y");
                        p29.setBackground(Color.yellow);
                        checkforWin();
                        checkforDraw();
                        playerTurn = true;
                }
           else
                        {
                                    if (p23.getText().equals(""))
                                {
                                        p23.setText("Y");
                                        p23.setBackground(Color.yellow);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = true;
                                }
           else
                        {
                                if (p17.getText().equals(""))
                             {
                                    p17.setText("Y");
                                    p17.setBackground(Color.yellow);
                                    checkforWin();
                                    checkforDraw();
                                    playerTurn = true;
                             }
            else
                        {
                                if (p11.getText().equals(""))
                                     {
                                          p11.setText("Y");
                                          p11.setBackground(Color.yellow);
                                          checkforWin();
                                          checkforDraw();
                                          playerTurn = true;
                                      }
                    
            else
                        {
                                    if (p5.getText().equals(""))
                                      {
                                        p5.setText("Y");
                                        p5.setBackground(Color.yellow);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = true;
                                      }
                                    else {JOptionPane.showMessageDialog(this, "COLUMN IS FILLED CHOOSE ANOTHER", "ERROR", 2);}
                         }
                        
                         }
                            
                         }
            
                         } 
            
                         }
        
                         }
        }
    }                                        

    private void jButton6ActionPerformed(java.awt.event.ActionEvent evt) {                                         
        // TODO add your handling code here:
       if (playerWon==true || computerWon== true || Draw==true)
        {
            out.setText("CLICK NEW GAME TO PLAY AGAIN");
        }
        else {
        if (playerTurn == true)
        {
            Turner.setText("YELLOW'S TURN (Player 2)");
            if (p36.getText().equals(""))
            {
                p36.setText("R");
                p36.setBackground(Color.red);
                checkforWin();
                checkforDraw();
                playerTurn = false;
            }
            else
            {
                    if (p30.getText().equals(""))
                {
                        p30.setText("R");
                        p30.setBackground(Color.red);
                        checkforWin();
                        checkforDraw();
                        playerTurn = false;
                }
           else
                        {
                                    if (p24.getText().equals(""))
                                {
                                        p24.setText("R");
                                        p24.setBackground(Color.red);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = false;
                                }
           else
                        {
                                if (p18.getText().equals(""))
                             {
                                    p18.setText("R");
                                    p18.setBackground(Color.red);
                                    checkforWin();
                                    checkforDraw();
                                    playerTurn = false;
                             }
            else
                        {
                                if (p12.getText().equals(""))
                                     {
                                          p12.setText("R");
                                          p12.setBackground(Color.red);
                                          checkforWin();
                                          checkforDraw();
                                          playerTurn = false;
                                      }
                    
            else
                        {
                                    if (p6.getText().equals(""))
                                      {
                                        p6.setText("R");
                                        p6.setBackground(Color.red);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = false;
                                      }
                                    else {JOptionPane.showMessageDialog(this, "COLUMN IS FILLED CHOOSE ANOTHER", "ERROR", 2);}
                         }
                        
                         }
                            
                         }
            
                         } 
            
                         }
        
                         }
        else 
        {
        {
            Turner.setText("RED'S TURN (Player 1)");
            if (p36.getText().equals(""))
            {
                p36.setText("Y");
                p36.setBackground(Color.yellow);
                checkforWin();
                checkforDraw();
                playerTurn = true;
            }
            else
            
                    if (p30.getText().equals(""))
                {
                        p30.setText("Y");
                        p30.setBackground(Color.yellow);
                        checkforWin();
                        checkforDraw();
                        playerTurn = true;
                }
           else
                        {
                                    if (p24.getText().equals(""))
                                {
                                        p24.setText("Y");
                                        p24.setBackground(Color.yellow);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = true;
                                }
           else
                        {
                                if (p18.getText().equals(""))
                             {
                                    p18.setText("Y");
                                    p18.setBackground(Color.yellow);
                                    checkforWin();
                                    checkforDraw();
                                    playerTurn = true;
                             }
            else
                        {
                                if (p12.getText().equals(""))
                                     {
                                          p12.setText("Y");
                                          p12.setBackground(Color.yellow);
                                          checkforWin();
                                          checkforDraw();
                                          playerTurn = true;
                                      }
                    
            else
                        {
                                    if (p6.getText().equals(""))
                                      {
                                        p6.setText("Y");
                                        p6.setBackground(Color.yellow);
                                        checkforWin();
                                        checkforDraw();
                                        playerTurn = true;
                                      }
                                    else {JOptionPane.showMessageDialog(this, "COLUMN IS FILLED CHOOSE ANOTHER", "ERROR", 2);}
                         }
                        
                         }
                            
                         }
            
                         } 
            
                         }
        }
        
        }
    }                                        

    private void jButton7ActionPerformed(java.awt.event.ActionEvent evt) {                                         
        // TODO add your handling code here:
        
        p1.setText(null);
        p2.setText(null);
        p3.setText(null);
        p4.setText(null);
        p5.setText(null);
        p6.setText(null);
        p7.setText(null);
        p8.setText(null);
        p9.setText(null);
        p10.setText(null);
        p11.setText(null);
        p12.setText(null);
        p13.setText(null);
        p14.setText(null);
        p15.setText(null);
        p16.setText(null);
        p17.setText(null);
        p18.setText(null);
        p19.setText(null);
        p20.setText(null);
        p21.setText(null);
        p22.setText(null);
        p23.setText(null);
        p24.setText(null);
        p25.setText(null);
        p26.setText(null);
        p27.setText(null);
        p28.setText(null);
        p29.setText(null);
        p30.setText(null);
        p31.setText(null);
        p32.setText(null);
        p33.setText(null);
        p34.setText(null);
        p35.setText(null);
        p36.setText(null);
        
        out.setText(null);
        
       p1.setBackground(Color.white);
       p2.setBackground(Color.white);
       p3.setBackground(Color.white);
       p4.setBackground(Color.white);
       p5.setBackground(Color.white);
       p6.setBackground(Color.white);
       p7.setBackground(Color.white);
       p8.setBackground(Color.white);
       p9.setBackground(Color.white);
       p10.setBackground(Color.white);
       p11.setBackground(Color.white);
       p12.setBackground(Color.white);
       p13.setBackground(Color.white);
       p14.setBackground(Color.white);
       p15.setBackground(Color.white);
       p16.setBackground(Color.white);
       p17.setBackground(Color.white);
       p18.setBackground(Color.white);
       p19.setBackground(Color.white);
       p20.setBackground(Color.white);
       p21.setBackground(Color.white);
       p22.setBackground(Color.white);
       p23.setBackground(Color.white);
       p24.setBackground(Color.white);
       p25.setBackground(Color.white);
       p26.setBackground(Color.white);
       p27.setBackground(Color.white);
       p28.setBackground(Color.white);
       p29.setBackground(Color.white);
       p30.setBackground(Color.white);
       p31.setBackground(Color.white);
       p32.setBackground(Color.white);
       p33.setBackground(Color.white);
       p34.setBackground(Color.white);
       p35.setBackground(Color.white);
       p36.setBackground(Color.white);
        
       playerTurn = true;
       playerWon = false;
       computerWon = false;
       Draw = false;
        
       Turner.setText("RED STARTS (PLAYER 1)");
        
    }                                        

    private void jButton8ActionPerformed(java.awt.event.ActionEvent evt) {                                         
       System.exit(0);
    }                                        

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Connect4.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Connect4.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Connect4.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Connect4.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Connect4().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify                     
    private javax.swing.JLabel Turner;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JButton jButton5;
    private javax.swing.JButton jButton6;
    private javax.swing.JButton jButton7;
    private javax.swing.JButton jButton8;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JTextField out;
    private javax.swing.JTextField p1;
    private javax.swing.JTextField p10;
    private javax.swing.JTextField p11;
    private javax.swing.JTextField p12;
    private javax.swing.JTextField p13;
    private javax.swing.JTextField p14;
    private javax.swing.JTextField p15;
    private javax.swing.JTextField p16;
    private javax.swing.JTextField p17;
    private javax.swing.JTextField p18;
    private javax.swing.JTextField p19;
    private javax.swing.JTextField p2;
    private javax.swing.JTextField p20;
    private javax.swing.JTextField p21;
    private javax.swing.JTextField p22;
    private javax.swing.JTextField p23;
    private javax.swing.JTextField p24;
    private javax.swing.JTextField p25;
    private javax.swing.JTextField p26;
    private javax.swing.JTextField p27;
    private javax.swing.JTextField p28;
    private javax.swing.JTextField p29;
    private javax.swing.JTextField p3;
    private javax.swing.JTextField p30;
    private javax.swing.JTextField p31;
    private javax.swing.JTextField p32;
    private javax.swing.JTextField p33;
    private javax.swing.JTextField p34;
    private javax.swing.JTextField p35;
    private javax.swing.JTextField p36;
    private javax.swing.JTextField p4;
    private javax.swing.JTextField p5;
    private javax.swing.JTextField p6;
    private javax.swing.JTextField p7;
    private javax.swing.JTextField p8;
    private javax.swing.JTextField p9;
    // End of variables declaration                   
}
