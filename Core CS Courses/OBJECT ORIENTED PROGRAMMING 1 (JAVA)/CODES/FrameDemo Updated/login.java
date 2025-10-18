import java.lang.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class login extends JFrame implements ActionListener
{
	JLabel label;
	JButton backBtn;
	JPanel panel;
	framedemo f1;
	
	public login(String s1,String s2,framedemo f1)
	{
		super("Login Gui");
		this.setSize(800, 450);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		this.f1=f1;
		
		panel = new JPanel();
		panel.setLayout(null);
		
		label = new JLabel("Text: "+s1+""+s2);
		label.setBounds(50,50,300,30);
		panel.add(label);
		
		
		backBtn = new JButton("Back");
		backBtn.setBounds(150, 150,80, 30);
		backBtn.addActionListener(this);
		panel.add(backBtn);
		
		this.add(panel);
		
		
	}
	public void actionPerformed(ActionEvent ae)
	{
		String command = ae.getActionCommand();
		
		if(backBtn.getText().equals(command))
		{
			framedemo fi = new framedemo();
			fi.setVisible(true);
			this.setVisible(false);
		}
		else
		{
			
		}
	}
}