import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class ValidateLogin
 */
@WebServlet(
	name = "ValidateLogin",
	urlPatterns = "/ValidateLogin"
)
public class ValidateLogin extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ValidateLogin() {
        super();
        // TODO Auto-generated constructor stub
    }
    
    //returns 1 for username doesn't exist, 2 for incorrect password, 3 for all correct, 4 for admin user
    public int validateUser(String username, String password) {
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		Boolean admin = false;
		try {
			conn = DriverManager.getConnection("jdbc:mysql://google/Project?cloudSqlInstance=myvirus:us-west1:myvir-database&socketFactory=com.google.cloud.sql.mysql.SocketFactory&useSSL=false&user=root&password=root");
			ps = conn.prepareStatement("SELECT user_id, username FROM users WHERE username=?");
			ps.setString(1, username);
			rs = ps.executeQuery();
			if(!rs.first()) {
				//username not in table
				return 1;
			}
			//here we know that username is in the database
			int id = rs.getInt("user_id");
			
			ps.close();
			rs.close();
			
			ps = conn.prepareStatement("SELECT pass_id FROM passwords WHERE user_id=? AND password=?");
			ps.setInt(1, id);
			ps.setString(2, password);
			rs = ps.executeQuery();
			if(!rs.first()) {
				//password from user doesn't match table password
				return 2;
			}
			ps.close();
			rs.close();

			//check for admin status
			ps = conn.prepareStatement("SELECT admin_status FROM users WHERE user_id=?");
			ps.setInt(1, id);

			rs = ps.executeQuery();
			rs.first();
			admin = rs.getBoolean("admin_status");
		}
		catch(SQLException sqle) {
			log ("oops sql exception");
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
		if(admin) return 4;
		else return 3;
	}
    
    protected void service(HttpServletRequest request, HttpServletResponse response)
        	throws ServletException, IOException {
    	String username = request.getParameter("username");
    	String password = request.getParameter("password");
    	int val = validateUser(username, password);
    	
    	if(val == 1 || val == 2) {
	    	PrintWriter out = response.getWriter();
			String error = "";
			error += "<p>";
	    	
	    	if(val == 1) {
	    		error += "Error: This user does not exist.";
	    	}
	    	else if(val == 2) {
	    		error += "Error: Incorrect password.";
	    	}
	    	error += "</p>";
			out.write(error);
			
			out.flush();
			out.close();
    	}

    	if(val == 4) {
    		PrintWriter out = response.getWriter();
    		String str = "ADMIN_USER";
    		out.write(str);
    		out.flush();
    		out.close();
    	}
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String username = request.getParameter("username");
    	String password = request.getParameter("password");
    	int val = validateUser(username, password);
    	
    	if(val == 1 || val == 2) {
	    	PrintWriter out = response.getWriter();
			String error = "";
			error += "<p>";
	    	
	    	if(val == 1) {
	    		error += "Error: This user does not exist.";
	    	}
	    	else if(val == 2) {
	    		error += "Error: Incorrect password.";
	    	}
	    	error += "</p>";
			out.write(error);
			
			out.flush();
			out.close();
    	}

    	if(val == 4) {
    		PrintWriter out = response.getWriter();
    		String str = "ADMIN_USER";
    		out.write(str);
    		out.flush();
    		out.close();
    	}
    	log("val is " + val);
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
