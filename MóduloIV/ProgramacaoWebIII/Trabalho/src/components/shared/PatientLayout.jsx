// src/components/shared/PatientLayout.jsx
import React from "react";
import { Outlet } from "react-router-dom";
import PatientSidebar from "./Sidebar/PatientSidebar";

export default function PatientLayout() {
  const userData = {
    name: "Paciente",
    email: "paciente@email.com",
  };

  return (
    <div className="flex h-screen">
      <PatientSidebar userData={userData} />
      <div className="flex-1 overflow-auto bg-gray-50">
        <Outlet />
      </div>
    </div>
  );
}