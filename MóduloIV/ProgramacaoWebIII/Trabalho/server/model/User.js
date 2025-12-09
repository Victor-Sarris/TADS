import { DataTypes } from "sequelize";
import conectDB from "../database/db";

const sequelize = await conectDB();

const User = sequelize.define("User", {
  id: {
    type: DataTypes.INTEGER,
    primaryKey: true,
    autoIncrement: true,
    allowNull: false,
  },
  name: { type: DataTypes.STRING, allowNull: false },
  email: { type: DataTypes.STRING, allowNull: false },
  password: { type: DataTypes.STRING, allowNull: false },
  phone:{ type: DataTypes.INTEGER, allowNull: false},
  gender: {type: DataTypes.STRING, allowNull: true},
  isValid: { type: DataTypes.BOOLEAN, defaultValue: true },
  role: {type: DataTypes.ENUM('admin', 'professional', 'patient'),
    defaultValue: 'patient',
    allowNull: true,
  },
});

await User.sync();

export default User;
