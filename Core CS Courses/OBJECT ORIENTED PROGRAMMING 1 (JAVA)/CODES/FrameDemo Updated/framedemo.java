import java.lang.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class framedemo extends JFrame implements MouseListener, ActionListener
{
	JPanel panel;
	JLabel userlable,passlable;
	JTextField passfield;
	JPasswordField pfield;
	JButton loginbtn,exitbtn,registerbtn;
	JRadioButton r1,r2,r3;
	JComboBox combo;
	Color mycolor, mycolor1;
	Font myfont;
	
	
	public framedemo()
	{
		super("My first Gui");
		this.setSize(800,500);
		
		mycolor = new Color(100,170,150);
		mycolor1 = new Color(0,0,0,1);
        myfont = new Font("Arial",Font.PLAIN,28);
		
		
		panel = new JPanel();
		panel.setLayout(null);
		panel.setBackground(mycolor);
		
		userlable = new JLabel("user");
		userlable.setBounds(150,115,100,30);
		userlable.setBackground(Color.RED);
		userlable.setOpaque(true);
		userlable.setForeground(Color.WHITE);
		userlable.setFont(myfont);
		panel.add(userlable);
		
		
	    passfield = new JTextField();
		passfield.setBounds(230,115,100,30);
		panel.add(passfield);
		
		passlable = new JLabel("Password:");
		passlable.setBounds(150,150,100,30);
		passlable.setBackground(Color.RED);
		passlable.setOpaque(true);
		panel.add(passlable);
		
		pfield = new JPasswordField();
		pfield.setBounds(230,150,100,30);
		panel.add(pfield);
		
		loginbtn = new JButton("LogIN");
		loginbtn.setBounds(180,200,80,30);
		loginbtn.setBackground(Color.RED);
		loginbtn.addMouseListener(this);
		loginbtn.addActionListener(this);
		panel.add(loginbtn);
		
		exitbtn = new JButton("Exit");
		exitbtn.setBounds(280,200,80,30);
		exitbtn.setBackground(Color.ORANGE);
		exitbtn.addMouseListener(this);
		exitbtn.addActionListener(this);
		panel.add(exitbtn);
		
		registerbtn = new JButton("Register");
	    registerbtn.setBounds(380,200,80,30);
		registerbtn.setBackground(Color.ORANGE);
		registerbtn.addMouseListener(this);
		registerbtn.addActionListener(this);
		panel.add(registerbtn);
		
		r1 = new JRadioButton("CSE");
		r1.setBounds(80,30,70,20);
		panel.add(r1);
		
		r2 = new JRadioButton("EEE");
		r2.setBounds(80,60,70,20);
		panel.add(r2);
		
		r3 = new JRadioButton("IPE");
		r3.setBounds(80,90,70,20);
		panel.add(r3);
		
		String items[]={"CSE","EEE","IPE","BBA"};
		combo = new JComboBox(items);
		combo.setBounds(150,70,100,30);
		panel.add(combo);
		
		
		this.add(panel);
			
	}
	
	public void mouseClicked(MouseEvent me){}
	public void mousePressed(MouseEvent me){}
	public void mouseReleased(MouseEvent me){}
	public void mouseEntered(MouseEvent me)
	{
		if(me.getSource()==loginbtn)
		{
			loginbtn.setBackground(Color.BLUE);
			loginbtn.setForeground(Color.WHITE);
		}
		else if(me.getSource()==exitbtn)
		{
			exitbtn.setBackground(Color.BLUE);
			exitbtn.setForeground(Color.WHITE);
		}
		else
		{
			
		}
	}
	
	public void mouseExited(MouseEvent me)
	{
		if(me.getSource()==loginbtn)
		{
			loginbtn.setBackground(Color.RED);
			loginbtn.setForeground(Color.BLACK);
		}
		else if(me.getSource()==exitbtn)
		{
			exitbtn.setBackground(Color.ORANGE);
			exitbtn.setForeground(Color.BLACK);
		}
	}
	
	public void actionPerformed(ActionEvent ae)
	{
			if(ae.getSource()==loginbtn)
			{
				String username=passfield.getText();
				String pass=pfield.getText();
				
				Account account=new Account();

				
			 if(account.getAccount(username,pass))
					
					{
						JOptionPane.showMessageDialog(null,"Sucessfull");
								
						login l1=new login(username,pass,this);
				        l1.setVisible(true);
				        this.setVisible(false);
						
					}
				
				else
				{
					JOptionPane.showMessageDialog(null,"Check Again");
			
				}
				
			}
			else if (ae.getSource()==registerbtn)
			{
				registration r1=new registration();
				r1.setVisible(true);
				this.setVisible(false);
			}
			else if(ae.getSource()==exitbtn)
			{
				System.exit(0);
			}
	
		
		
		
	}
	
	
	
	
	
}
