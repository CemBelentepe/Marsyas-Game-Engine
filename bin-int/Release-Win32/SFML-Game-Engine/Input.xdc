<?xml version="1.0"?><doc>
<members>
<member name="F:mge.Mathf.E" decl="false" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="9">
<summary>
Euler's number, constant e.
</summary>
</member>
<member name="F:mge.Mathf.PI" decl="false" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="13">
<summary>
The famous Pi = 3.14159265.... 
</summary>
</member>
<member name="F:mge.Mathf.err" decl="false" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="17">
<summary>
Error for calculating algothms to stop when they reach to. (For floats 1E-7 is almost a 0)
</summary>
</member>
<member name="F:mge.Mathf.max_complexity" decl="false" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="21">
<summary>
Maximum number of iterations for calculating algorithms.
</summary>
</member>
<member name="M:mge.Mathf.clamp(System.Single,System.Single,System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="27">
<summary>
Returns a clamps of a value between two values.
</summary>
<param name="x">Value to clamp.</param>
<param name="min">Min value</param>
<param name="max">Max value</param>
<returns>Value clamped between min and max.</returns>
</member>
<member name="M:mge.Mathf.abs(System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="35">
<summary>
Takes the absoulte value of x.
</summary>
<param name="x">Value to get absoulte.</param>
<returns>Absoulute value of x</returns>
</member>
<member name="M:mge.Mathf.floor(System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="41">
<summary>
Floors the number x.
</summary>
<param name="x">Value to get the floor.</param>
<returns>Returns the greatest integer smaller then x.</returns>
</member>
<member name="M:mge.Mathf.ceil(System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="47">
<summary>
Takes the ceil of number x.
</summary>
<param name="x">Value to get the ceil.</param>
<returns>Returns the smallest integer greater then x</returns>
</member>
<member name="M:mge.Mathf.max(System.Int32,System.Int32)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="53">
<summary>
Returns the maximum of a and b.
</summary>
<param name="a">Value.</param>
<param name="b">Value.</param>
<returns>Maximum of a and b.</returns>
</member>
<member name="M:mge.Mathf.min(System.Int32,System.Int32)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="60">
<summary>
Returns the minimum of a and b.
</summary>
<param name="a">Value.</param>
<param name="b">Value.</param>
<returns>Minimum of a and b</returns>
</member>
<member name="M:mge.Mathf.max(System.Single,System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="67">
<summary>
Returns the maximum of a and b.
</summary>
<param name="a">Value.</param>
<param name="b">Value.</param>
<returns>Maximum of a and b.</returns>
</member>
<member name="M:mge.Mathf.min(System.Single,System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="74">
<summary>
Returns the minimum of a and b.
</summary>
<param name="a">Value.</param>
<param name="b">Value.</param>
<returns>Minimum of a and b</returns>
</member>
<member name="M:mge.Mathf.pow(System.Single,System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="81">
<summary>
Raises base to the power <param name="power">power</param>.
</summary>
<param name="base">Base to raise.</param>
<param name="power">Power parameter.</param>
<returns>Returns base^power.</returns>
</member>
<member name="M:mge.Mathf.pow(System.Single,System.Int32)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="88">
<summary>
Raises base to the power <param name="power">power</param>.
</summary>
<param name="base">Base to raise.</param>
<param name="power">Power parameter.</param>
<returns>Returns base^power.</returns>
</member>
<member name="M:mge.Mathf.root(System.Single,System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="95">
<summary>
Takes the root of number to 'degree'th root
</summary>
<param name="number">Number to take root.</param>
<param name="degree">Degree of root.</param>
<returns>Returns number^(1/degree).</returns>
</member>
<member name="M:mge.Mathf.sqrt(System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="102">
<summary>
Takes the square root of number.
</summary>
<param name="number">Number to get the square root.</param>
<returns>Returns number^0.5.</returns>
</member>
<member name="M:mge.Mathf.Q_rsqrt(System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="108">
<summary>
Fast inverse square rooting algorithm from Quake 3.
<para>Used for normalization of vectors.</para>
</summary>
<param name="number">Number to take inverse square root.</param>
<returns>Returns ~1/sqrt(number).</returns>
</member>
<member name="M:mge.Mathf.factorial(System.UInt32)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="115">
<summary>
Calculates n!= n*(n-1)!.
Returns n!.
</summary>
<param name="n">Number to calculate its factorial</param>
<returns>Returns n!.</returns>
</member>
<member name="M:mge.Mathf.rand01" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="124">
<summary>
Returns a random value between 0 and 1.
</summary>
<returns>Random value between 0 and 1</returns>
</member>
<member name="M:mge.Mathf.rand(System.Single,System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="129">
<summary>
Returns a random value between a and b.
</summary>
<param name="a">Minimum of random value.</param>
<param name="b">Maximum of random value.</param>
<returns>Random value between a and b.</returns>
</member>
<member name="M:mge.Mathf.rand(System.Int32,System.Int32)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="136">
<summary>
Returns a random value between a and b.
</summary>
<param name="a">Minimum of random value.</param>
<param name="b">Maximum of random value.</param>
<returns>Random value between a and b.</returns>
</member>
<member name="M:mge.Mathf.rand(System.Int32)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="143">
<summary>
Returns a random value between 0 and b.
</summary>
<param name="a">Maximum of random value.</param>
<returns>Random value between a and b.</returns>
</member>
<member name="M:mge.Mathf.setRandSeed(System.UInt32)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="149">
<summary>
Sets the seed of random calculator.
</summary>
<param name="seed">Seed of random system.</param>
</member>
<member name="M:mge.Mathf.log(System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="167">
<summary>
Returns natural log of number.
</summary>
<param name="number">Number to take the log of.</param>
<returns>Returns ln(number).</returns>
</member>
<member name="M:mge.Mathf.log(System.Single,System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="173">
<summary>
Returns log of number in base base.
</summary>
<param name="number">Number to calculate the log of.</param>
<param name="base">Base of log.</param>
<returns>Returns ln(number)/ln(base).</returns>
</member>
<member name="M:mge.Mathf.exp(System.Single)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="180">
<summary>
Returns Euler's number e to the power power
</summary>
<param name="power">Power to calculate.</param>
<returns>Returns e^power</returns>
</member>
<member name="M:mge.Mathf.exp(System.Int32)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Mathf.h" line="186">
<summary>
Returns Euler's number e to the power power
</summary>
<param name="power">Power to calculate.</param>
<returns>Returns e^power</returns>
</member>
<member name="M:mge.Input.start(sf.RenderWindow*)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Input.h" line="56">
<summary>
Starts the Input system at the window.
</summary>
<param name="window">Window to listen.</param>
</member>
<member name="M:mge.Input.setWindow(sf.RenderWindow*)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Input.h" line="64">
<summary>
Sets the listening window.
</summary>
<param name="window">Window to listen.</param>
</member>
<member name="M:mge.Input.reset" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Input.h" line="69">
<summary>
Resets the Input system.
</summary>
</member>
<member name="M:mge.Input.updateMouseButtonPressed(sf.Mouse.Button,System.Int32)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Input.h" line="74">
<summary>
Updates mouse button state.
</summary>
<param name="button">Button to update.</param>
<param name="value">State of the button.</param>
</member>
<member name="M:mge.Input.updateKeyPressed(sf.Keyboard.Key,System.Int32)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Input.h" line="80">
<summary>
Updates the keyboard button state.
</summary>
<param name="key">Key to update.</param>
<param name="value">State of the key</param>
</member>
<member name="M:mge.Input.getMousePosition" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Input.h" line="87">
<summary>
Returns the mouse position.
</summary>
<returns>Mouse position.</returns>
</member>
<member name="M:mge.Input.isMouseButtonPressed(mge.Input.MouseButton)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Input.h" line="92">
<summary>
Returns if the mouse button is pressed.
</summary>
<param name="button">Mouse button.</param>
<returns>State of the mouse button.</returns>
</member>
<member name="M:mge.Input.getMouseButtonDown(mge.Input.MouseButton)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Input.h" line="98">
<summary>
Returns whether if the mouse buton is pressed at that frame. Some kind of trigger.
</summary>
<param name="button">Mouse button.</param>
<returns>Returns if it is pressed at that frame.</returns>
</member>
<member name="M:mge.Input.getMouseButtonUp(mge.Input.MouseButton)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Input.h" line="104">
<summary>
Returns whether if the mouse buton is released at that frame. Some kind of trigger.
</summary>
<param name="button">Mouse button.</param>
<returns>Returns if it is released at that frame</returns>
</member>
<member name="M:mge.Input.isKeyPressed(mge.Input.Key)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Input.h" line="111">
<summary>
Returns if the key is pressed.
</summary>
<param name="key">Keyboard key to control</param>
<returns>Returns the state of the key.</returns>
</member>
<member name="M:mge.Input.getKeyDown(mge.Input.Key)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Input.h" line="117">
<summary>
Returns whether if the key is pressed at that frame. Some kind of trigger.
</summary>
<param name="key">Keyboard key to control</param>
<returns>Returns if it is pressed at that frame.</returns>
</member>
<member name="M:mge.Input.getKeyUp(mge.Input.Key)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Input.h" line="123">
<summary>
Returns whether if the key is released at that frame. Some kind of trigger.
</summary>
<param name="key">Keyboard key to control</param>
<returns>Returns if it is released at that frame.</returns>
</member>
<member name="M:mge.Debug.setColor(mge.Debug.LogState)" decl="true" source="P:\Repos\GitHub\SFML-Game-Engine\SFML-Game-Engine\Debug.h" line="14">
<summary>
Sets the color of the console based on enum type LogState.
</summary>
<param name="state">Console color state.</param>
</member>
</members>
</doc>