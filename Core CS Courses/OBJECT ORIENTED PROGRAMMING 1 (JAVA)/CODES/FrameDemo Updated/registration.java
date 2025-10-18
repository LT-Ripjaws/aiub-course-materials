import java.lang.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class registration extends JFrame implements MouseListener, ActionListener
{
	JPanel panel;
	JLabel userlable,passlable;
	JTextField passfield;
	JPasswordField pfield;
	JButton signbtn,exitbtn;
	Color mycolor, mycolor1;
	Font myfont;
	
	
	public registration ()
	{
		super("Registration");
		this.setSize(800,500);
		
		panel = new JPanel();
		panel.setLayout(null);
		
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
		
		signbtn= new JButton("Signup");
		signbtn.setBounds(180,200,80,30);
		signbtn.setBackground(Color.RED);
		signbtn.addMouseListener(this);
		signbtn.addActionListener(this);
		panel.add(signbtn);
		
		exitbtn = new JButton("Exit");
		exitbtn.setBounds(280,200,80,30);
		exitbtn.setBackground(Color.ORANGE);
		exitbtn.addMouseListener(this);
		exitbtn.addActionListener(this);
		panel.add(exitbtn);
		
		this.add(panel);
	}
	public void mouseClicked(MouseEvent me){}
	public void mousePressed(MouseEvent me){}
	public void mouseReleased(MouseEvent me){}
	public void mouseEntered(MouseEvent me){}
	
	public void mouseExited(MouseEvent me){}
	
	public void actionPerformed(ActionEvent ae)
	{
		
			if (ae.getSource()==signbtn)
			{
				String name=passfield.getText();
				String pass=pfield.getText();
				
				if(name.isEmpty()||pass.isEmpty())
				{
					JOptionPane.showMessageDialog(null,"fill all");
				}
				
				else{
					Account account=new Account(name,pass);
					account.addaccount();
					JOptionPane.showMessageDialog(null,"added");
					
					passfield.setText("");
					pfield.setText("");
					
					
					framedemo f2=new framedemo();
				    f2.setVisible(true);
				    this.setVisible(false);
				}
				
				
				
				
			}
			else if(ae.getSource()==exitbtn)
			{
				System.exit(0);
			}
		
	}
	
}