import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class ValidateRegister
 */
@WebServlet("/ValidateRegister")
public class ValidateRegister extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ValidateRegister() {
        super();
        // TODO Auto-generated constructor stub
    }
    
    //return 1 for username already taken, 2 for passwords don't match, 3 for all correct
  	public int validate(String username, String pass1, String pass2) {
  		if(!pass1.equals(pass2)) {
  			return 2;
  		}
  		Connection conn = null;
  		PreparedStatement ps = null;
  		ResultSet rs = null;
  		try {
  			conn = DriverManager.getConnection("//insert jdbc here");
  			ps = conn.prepareStatement("SELECT username FROM users WHERE username=?");
  			ps.setString(1, username);
  			rs = ps.executeQuery();
  			if(rs.first()) {
  				//username is in table, already taken
  				return 1;
  			}
  			rs.close();
  			
  			ps.close();
  			//add username and password to database
  			ps = conn.prepareStatement("INSERT INTO users (username, admin_status) VALUES (?, false)");
  			ps.setString(1, username);
  			ps.executeUpdate();
  			ps.close();
  			
  			ps = conn.prepareStatement("SELECT user_id from users WHERE username=?");
  			ps.setString(1, username);
  			rs = ps.executeQuery();
  			rs.next();
			int id = rs.getInt("userID");
			ps.close();
			
  			ps = conn.prepareStatement("INSERT INTO passwords (user_id, password) VALUES (?, ?)");
  			ps.setInt(1, id);
  			ps.setString(2, pass1);
  			ps.executeUpdate();
  			ps.close();
  		}
  		catch(SQLException sqle) {
  			System.out.println(sqle.getMessage());
  		}
  		finally {
  			try {
  				if(rs != null) {
  					rs.close();
  				}
  				if(ps != null) {
  					ps.close();
  				}
  				if(conn != null) {
  					conn.close();
  				}
  			}
  			catch (SQLException sqle) {
  				System.out.println(sqle.getMessage());
  			}
  		}
  		
  		return 3;
  	}

  	
  	protected void service(HttpServletRequest request, HttpServletResponse response)
        	throws ServletException, IOException {
    	String username = request.getParameter("username");
    	String pass1 = request.getParameter("pass1");
    	String pass2 = request.getParameter("pass2");
    	int val = validate(username, pass1, pass2);
    	
    	if(val == 1 || val == 2) {
	    	PrintWriter out = response.getWriter();
			String error = "";
			//error += "<p>";
	    	
	    	if(val == 1) {
	    		error += "Error: This username is already taken.";
	    	}
	    	else if(val == 2) {
	    		error += "Error: The passwords do not match.";
	    	}
	    	//error += "</p>";
			out.write(error);
			
			out.flush();
			out.close();
    	}
    }
  	
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
