#include <vector>

using namespace std;

// Identity matrix
namespace constants
{
	// Initial Process Covariance matrix
	const float init_var_pos_x = 10.0F;
	const float init_var_pos_y = 10.0F;
	const float init_var_vel_x = 10.0F;
	const float init_var_vel_y = 10.0F;

	// Measurement Noise Covariance matrix
	const float meas_var_pos_x = 1.0F;
	const float meas_var_pos_y = 0.5F;
	const float meas_var_vel_x = 1.0F;
	const float meas_var_vel_y = 1.0F;

	// Process Noise Covariance matrix
	const float process_var_pos_x = 0.0F;
	const float process_var_pos_y = 0.0F;
	const float process_var_vel_x = 0.0F;
	const float process_var_vel_y = 0.0F;
}




